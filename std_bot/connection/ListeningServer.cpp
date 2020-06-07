#include "ListeningServer.h"

sp<thread> ListeningServer::beginListening(){
    
    // Initializes listening socket
    if(!(listeningSocket = socket(AF_INET, SOCK_STREAM, 0))){
        Logger::write("Cannot build the listening socket.", LOG_ERROR);
        return nullptr;
    }

    // Configures listening socket
    int opt = 1;
    if(setsockopt(listeningSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        Logger::write("Cannot configure the listening socket.", LOG_ERROR);
        return nullptr;
    }

    // Configures accpted adresses (all) and listening port
    listeningAddr.sin_family = AF_INET;
    listeningAddr.sin_addr.s_addr = INADDR_ANY;
    listeningAddr.sin_port = htons(listeningPort);

    // Binds the socket to the port
    if(bind(listeningSocket, (sockaddr *) &listeningAddr, sizeof(listeningAddr)) < 0) {
        Logger::write("Cannot bind adress and listening socket.", LOG_ERROR);
        return nullptr;
    }

    // Begin the listening
    if(listen(listeningSocket, 0) < 0){
        Logger::write("Cannot listen to the socket.", LOG_ERROR);
        return nullptr;
    }

    // If everything is sucessful, sets object's variables accordingly and start the thread
    run = true;
    listeningThread = make_shared<thread>(&ListeningServer::listenLoop, this);

    return listeningThread;
}

void ListeningServer::listenLoop(){
    // Creates a file descriptor for the pselect function
    fd_set fileDescriptor;
    FD_ZERO(&fileDescriptor);

    // 1 sec timeout for the pselect function.
    timespec timeout;
    timeout.tv_sec = 1;
    timeout.tv_nsec = 0;

    // Variable for the accpet function
    int addrlen = sizeof(listeningAddr);

    // Loops
    while (run) {    

        // Locks the access to the connections' vector
        unique_lock<timed_mutex> connectionsLock(connectionsMutex, defer_lock);
        if(connectionsLock.try_lock_for(chrono::milliseconds(10))){
            // Discards the unvalid connections
            for (int i = 0; i < orphanConnections.size(); i++){
                if(!orphanConnections[i]) {
                    orphanConnections.erase(orphanConnections.begin() + i);
                    i--;
                }
            }
            for (int i = 0; i < connections.size(); i++){
                if(connections[i].expired()) {
                    connections.erase(connections.begin() + i);
                    i--;
                }
            }

            connectionsLock.unlock();
        }

        // Sets the file descriptor with the listening socket
        FD_SET(listeningSocket, &fileDescriptor);

        // Checks if there is any incoming connection
        int sel = pselect(listeningSocket + 1, &fileDescriptor, NULL, NULL, &timeout, NULL);
        if(sel < 0){
            // If pselect return a negative integer, there was an error.

            // Logs the error
            Logger::write("Error on listening socket. Terminating the listening loop.", LOG_ERROR);
            // Stops the loop
            run = false;
        } else if (sel > 0){
            // If pselect returns a striclty positive integer, there is a incoming connection

            // Get a new socket for the incoming connection
            int newSocket = accept(listeningSocket, (sockaddr *) &listeningAddr, (socklen_t *) &addrlen);

            if(newSocket < 0){
                // If the socket is negative, it is invalid

                // Logs the error
                Logger::write("Cannot accept incoming connection.", LOG_ERROR);
            } else {

                //Checks if the maximum number of connections has been reached
                if(maxConnections != -1 && connections.size() >= maxConnections) {
                    // If so, logs the error
                    Logger::write("Connection refused : too many connections are already beeing handled.", LOG_INFO);
                    // Refuses the connection
                    refuseConnection(newSocket);
                } else {
                    // Accepts the connection
                    sp<ServerConnection> newConnection = acceptConnection(newSocket);

                    if(newConnection){
                        // Adds the new connection to the unmanaged connections array, synchronously 
                        if(connectionsLock.try_lock_for(chrono::seconds(1))){
                            orphanConnections.push_back(newConnection);
                            // lastConnection = newConnection;
                            newConnection->onConnection();
                            connectionsLock.unlock();
                        } else {
                            Logger::write("Could not accept a connection because the connections' vector was blocked for too long. There might be a deadlock!", LOG_ERROR);
                            refuseConnection(newSocket);
                            continue;
                        }
                    } else {
                        // If the connection could not be accepted, refuse it.
                        refuseConnection(newSocket);
                    }
                }
            }
        }
    }
}

void ListeningServer::refuseConnection(int serverConnectionSocket){
    // close the new socket
    close(serverConnectionSocket);
}

sp<ServerConnection> ListeningServer::getLastConnection(){

    // Tries to access the unmanaged connections vector
    unique_lock<timed_mutex> connectionsLock(connectionsMutex, defer_lock);
    if(connectionsLock.try_lock_for(chrono::milliseconds(100))){

        // If the vector is empty, returns nullptr
        if(orphanConnections.size() <= 0)
            return nullptr;

        // Else, returns the last connection
        sp<ServerConnection> connection = orphanConnections.back();
        orphanConnections.pop_back();
        connections.push_back(connection);

        return connection;
    } else {
        Logger::write("Could not access the connections' vector. Careful of deadlocks.", LOG_WARNING);
        return nullptr;
    }
}

template<typename T>
sp<T> ListeningServer::getConnection(){

    // Tries to access unmanaged connections' vector
    unique_lock<timed_mutex> connectionsLock(connectionsMutex, defer_lock);
    if(connectionsLock.try_lock_for(chrono::milliseconds(10))) {

        // Returns the first connection that cast to T
        for(sp<ServerConnection> oc : orphanConnections){
            if(dynamic_pointer_cast<T>(oc))
                return oc;
        }

        for(weak_ptr<ServerConnection> c : connections){
            if(dynamic_pointer_cast<T>(c))
                return c;
        }

    } else {
        Logger::write("Could not access the connections' vector. Careful of deadlocks.", LOG_WARNING);
        return nullptr;       
    }
}

template<typename T>
sp<T> ListeningServer::getConnection(function<bool(sp<ServerConnection>)> filter){

    // Tries to access connections' vectors
    unique_lock<timed_mutex> connectionsLock(connectionsMutex, defer_lock);
    if(connectionsLock.try_lock_for(chrono::milliseconds(10))) {

        // Returns the first connection that cast to T and makes filter return true
        for(sp<ServerConnection> oc : orphanConnections){
            sp<T> T_cast = dynamic_pointer_cast<T>(oc);
            if(T_cast && filter(T_cast))
                return oc;
        }

        for(weak_ptr<ServerConnection> c : connections){
            sp<T> T_cast = dynamic_pointer_cast<T>(c);
            if(T_cast && filter(T_cast))
                return c;
        }

    } else {
        Logger::write("Could not access the connections' vector. Careful of deadlocks.", LOG_WARNING);
        return nullptr;       
    }
}