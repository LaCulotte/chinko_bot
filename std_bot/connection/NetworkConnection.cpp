#include "NetworkConnection.h"

NetworkConnection::NetworkConnection(){
    // Sets the file descriptor
    FD_ZERO(&rfd);

    // Sets the description
    connectionDescription = "NetworkConnection";
}

NetworkConnection::NetworkConnection(const NetworkConnection& other){
    // Sets the file descriptor
    FD_ZERO(&rfd);

    // Sets the description
    connectionDescription = other.connectionDescription;
}

NetworkConnection& NetworkConnection::operator=(const NetworkConnection& other){
    // Sets the file descriptor
    FD_ZERO(&rfd);

    // Sets the description
    connectionDescription = other.connectionDescription;

    return *this;
}

NetworkConnection::~NetworkConnection(){
    // Disconnects before destruction
    this->disconnect();
}

sp<MessageDataBuffer> NetworkConnection::readData(int length){
    // Message databuffer to return   
    sp<MessageDataBuffer> ret(nullptr);

    // Do something if there is data to read
    if (isThereMessage()) {
        // Reads 'length' Bytes
        uchar *data = (uchar *) malloc(length * sizeof(uchar));
        int recv_len = recv(sock, data, length, 0);

        if(recv_len == 0){
            // If the length is 0, while it annonced that there was data to read, it means that the connection was closed

            // Logs the deconnection
            Logger::write("Error while reading data from " + connectedAddress + " : connection was closed.", LOG_WARNING);
            // Properly close the local side of the connection
            this->disconnect();

            // Returns a nullptr
            return ret;
            
        } else if (recv_len > length) {
            // If the received length is greater than the length asked, there is a concerning problem (it is never sopposed to happend)

            // Logs the error
            Logger::write("Big error while reading data : somehow read more data than intended. Actual read length : " + to_string(recv_len) + "; Intended read length :" + to_string(length) + ";", LOG_ERROR);
            // Raises an exception to raise concern. To delete for proper realase.
            assert(false);
            
            // Return a nullptr
            return ret;
        }

        // If everything is ok, initialize the returning data buffer
        ret = make_shared<MessageDataBuffer>(data, recv_len);
    }

    // Returns the read data buffer
    return ret;
}

bool NetworkConnection::writeData(sp<MessageDataBuffer> data){
    //Cannot write data if the connection is not connected; return false
    if(!connected)
        return false;

    // Send data
    int send_ret = send(sock, data->toCharArray(), data->size(), 0);

    if(send_ret == -1){
        // If the send was unsuccessful

        //Logs error
        Logger::write("Error while sending data to " + connectedAddress + ".", LOG_WARNING);
        // Logger::write("todo later ? get and display error id and message", LOG_INFO);
        // -> getsockopt?

        return false;
    }

    if(send_ret < data->size()){
        // If not all data was sent

        // Logs error
        Logger::write("Error while sending data to " + connectedAddress + ".", LOG_WARNING);
        Logger::write(to_string(send_ret) + " bytes sent instead of " + to_string(data->size()) + ".", LOG_WARNING); 

        return false;
    }

    // Check if there was an error while sending the message
    int error_code;
    int error_code_size = sizeof(error_code);
    int get_ret = getsockopt(sock, SOL_SOCKET, SO_ERROR, &error_code, (socklen_t *) &error_code_size);

    if(get_ret != 0){
        // Logs error
        Logger::write("Error while sending data : " + (string) strerror(get_ret) + ". Connection will be closed.", LOG_WARNING);
        // Disconnects
        this->disconnect();

        return false;
    }
    if(error_code != 0){
        // Logs error
        Logger::write("Error while sending data : " + (string) strerror(error_code) + ". Connection will be closed.", LOG_WARNING);
        // Disconnects
        this->disconnect();

        return false;
    }


    // The send was successful, returns true
    return true;
}

bool NetworkConnection::isThereMessage(){
    // There is no message to read if the connection is not connected
    if(!connected)
        return false;
        
    // Use select to know if there is data to read
    FD_SET(sock, &rfd);
    int sel_ret = select(sock + 1, &rfd, NULL, NULL, (timeval *) &selectTimeout);

    if(sel_ret < 0){
        // If select returns a negative integer, there is an error

        // Logs error
        Logger::write("Error on connection with " + connectedAddress + ". Closing connection.", LOG_IMPORTANT_WARNING);
        // Logger::write("todo later ? get and display error id and message", LOG_INFO);
        // getsockopt

        // Disconnects
        this->disconnect();

        return false;
    }

    // There is data (therefore messages) to read if select return a strictly positive integer 
    return (sel_ret > 0);
}

void NetworkConnection::emptySocketBuffer(){
    // Reads 1000 Bytes while the buffer is not empty
    while(isThereMessage()){
        readData(1000);
    }

    return;
}

bool NetworkConnection::isConnected(){
    return connected;
}