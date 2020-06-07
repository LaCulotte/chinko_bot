#ifndef LISTENINGSERVER_H
#define LISTENINGSERVER_H

#include "socket_include.h"
#include "thread_include.h"
#include "ServerConnection.h"
#include <functional>

class ListeningServer {
public:
    // Constructor
    ListeningServer() {};
    // Constructor with listening port initialisation
    ListeningServer(int listeningPort) { this->listeningPort = listeningPort; };
    // Constructor with listening port and the maximum number of connections initialisation
    ListeningServer(int listeningPort, int maxConnections) { this->listeningPort = listeningPort; this->maxConnections = maxConnections; };
    // Copy constructor
    ListeningServer(const ListeningServer& other) = delete;

    // Copy operator
    virtual ListeningServer& operator=(const ListeningServer& other) = delete;
    // Destructor
    virtual ~ListeningServer() = default;

    // Lauches the listening thread
    sp<thread> beginListening();
    // Stops the listening thread
    bool stop() { run = false; listeningThread->join(); listeningThread.reset(); return true; };

    // Returns the last unmanaged incoming connection
    sp<ServerConnection> getLastConnection();
    // Returns the first connection that is a child of T
    template<typename T>
    sp<T> getConnection();
    // Returns the first connection that is a child of T and that makes 'filter' return true
    template<typename T>
    sp<T> getConnection(function<bool(sp<ServerConnection>)> filter);

protected:
    // Vector of weak pointers of the incoming connections that are being managed
    vector<weak_ptr<ServerConnection>> connections;
    // Vector of shared pointers of the incoming connections that are not being managed yet
    vector<sp<ServerConnection>> orphanConnections;
    // Mutex to synchrinize the access to the connections' arrays
    timed_mutex connectionsMutex;

    // Turns a socket into a wanted serverConnection. To implement in override in order to return an object of the wanted type
    virtual sp<ServerConnection> acceptConnection(int serverConnectionSocket) = 0;
    // Closes the connection associated to 'serverConnectionSocket'. To implement if a special action is necessary on close.
    virtual void refuseConnection(int serverConnectionSocket);

    // Loop that checks if there is incoming connections
    virtual void listenLoop();

    // Thread that runs loop
    sp<thread> listeningThread;
    // Socket that is listening for incoming connections
    int listeningSocket;
    // Port on which the incoming connections are detected
    int listeningPort = 5555;
    // Type of addresses to accept
    sockaddr_in listeningAddr;

    // True if the loop is running
    bool run = false;
    // Maximum number of connections that can be accepted by the server. If -1, there is no maximum.
    int maxConnections = -1;
};

#endif