#ifndef ADD_CONNECTION_MESSAGE
#define ADD_CONNECTION_MESSAGE

#include "Message.h"
#include "Connection.h"

class AddConnectionMessage : public Message {
public:
    // Contructor
    AddConnectionMessage() {};
    // Constructor; 'connection' will be connected to 'destAddress', to 'destPort'
    AddConnectionMessage(sp<Connection> connection) { newConnection = connection;};
    // Copy constuctor
    AddConnectionMessage(const AddConnectionMessage& other) = default;

    // Copy operator
    virtual AddConnectionMessage& operator=(const AddConnectionMessage& other) = default;
    // Destructor
    virtual ~AddConnectionMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; }

    // Message's protocol Id
    static const unsigned int protocolId = 10023;

    // Connection that will be added to ConnectionUnit
    sp<Connection> newConnection;
}; 

#endif