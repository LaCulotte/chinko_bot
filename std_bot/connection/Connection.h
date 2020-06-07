#ifndef CONNECTION_H
#define CONNECTION_H

#include "std_include.h"
#include "ptr_include.h"
#include "Logger.h"
#include "ConnectionMessage.h"
#include "MessageTypeHandler.h"

// Interface for a connection, that can be a network connection or any other type
class Connection{
public:
    // Constructor
    Connection() {};
    // Copy constructor
    Connection(const Connection& other) { connectionDescription = other.connectionDescription; };

    // Copy operator
    virtual Connection& operator=(const Connection& other) { connectionDescription = other.connectionDescription; return *this; };
    // Desctructor
    virtual ~Connection() = default;

    // Initialize the connection's MessageTypeHandler
    virtual void initHandler() = 0; 

    // Receive a message through connection
    virtual sp<ConnectionMessage> readMessage() = 0;
    // Receive mutliple messages through connection
    virtual vector<sp<ConnectionMessage>> readMessages(int n, bool fill = true) = 0;
    // Receive all messages through connection
    virtual vector<sp<ConnectionMessage>> readAllMessages() = 0;

    // Send a message through connection
    virtual bool sendMessage(sp<ConnectionMessage> message) = 0;
    // Returns true if there is a message to read. In this case, readMessage should not return nullptr in normal conditions
    virtual bool isThereMessage() = 0; 

    // Returns true if the connection is connected, ie. can read and send messages
    virtual bool isConnected() = 0;
    // Disconnects the connection
    virtual void disconnect() = 0;
    
    // Connection description. Used to differentiate special connections in an array or a map
    string connectionDescription = "Connection";

protected:
    // True if the connection is connected
    bool connected = false;

    // Sends raw data from a MessageDataBuffer through connection
    virtual bool writeData(sp<MessageDataBuffer> data) = 0;
    // Reads raw data from a MessageDataBuffer through connection
    virtual sp<MessageDataBuffer> readData(int length) = 0;

    // MessageTypeHandler used to get a message from data read with readData 
    sp<MessageTypeHandler> messageTypeHandler;
};

#endif