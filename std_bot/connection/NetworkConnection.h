#ifndef NETWORKCONNECTION_H
#define NETWORKCONNECTION_H

#include "socket_include.h"
#include "Connection.h"
#include "Logger.h"
#include "NetworkMessage.h"

// Connection used to send messages through the TCP/IP protocol
class NetworkConnection : public Connection {
public:
    // Constructor
    NetworkConnection();
    // Copy constructor
    NetworkConnection(const NetworkConnection& other);

    // Copy operator
    virtual NetworkConnection& operator=(const NetworkConnection& other); 
    // Destructor
    virtual ~NetworkConnection();

    // Disconnects
    virtual void disconnect() override { close(sock); connected = false; };
    // Returns connected
    bool isConnected() override;
    // Remote initialization of the connection's socket
    void setSocket(int sock) { this->sock = sock; connected = isConnected(); };

    // Returns true if there is messages to read
    virtual bool isThereMessage() override;

protected:

    // Socket of the current connection
    int sock;
    // Address of the current connection
    string connectedAddress;

    // Empties de socket buffer (reads 1000 Bytes over and over)    
    void emptySocketBuffer();

    // File descriptor set, here used with select to tell if
    // there is data to read in the socket 
    fd_set rfd;

    // Timeout for select to tell if there is data to read
    // in the socket
    const timeval selectTimeout = {0, 0};

    // Sends raw data from a MessageDataBuffer through connection
    virtual bool writeData(sp<MessageDataBuffer> data) override;
    // Reads raw data from a MessageDataBuffer through connection
    virtual sp<MessageDataBuffer> readData(int length) override;
};

#endif