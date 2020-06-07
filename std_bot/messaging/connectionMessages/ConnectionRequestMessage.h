#ifndef CONNECTION_REQUEST_MESSAGE
#define CONNECTION_REQUEST_MESSAGE

#include "Message.h"
#include "ClientConnection.h"
#include <functional>

class ConnectionRequestMessage : public Message {
public:
    // Contructor
    ConnectionRequestMessage() {};
    // Constructor; 'connection' will be connected to 'destAddress', to 'destPort'
    ConnectionRequestMessage(sp<ClientConnection> connection, string destAddress, int destPort) { toConnect = connection; address = destAddress; port = destPort; };
    // Constructor; connection built with 'builder' will be connected to 'destAddress', to 'destPort'
    ConnectionRequestMessage(function<sp<ClientConnection>()> builder, string destAddress, int destPort) { connectionBuilder = builder; address = destAddress; port = destPort; };
    // Copy constuctor
    ConnectionRequestMessage(const ConnectionRequestMessage& other) = default;

    // Copy operator
    virtual ConnectionRequestMessage& operator=(const ConnectionRequestMessage& other) = default;
    // Destructor
    virtual ~ConnectionRequestMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; }

    // Message's protocol Id
    static const unsigned int protocolId = 613;

    // Connection to connect with ConnectionUnit
    sp<ClientConnection> toConnect;
    // The ConnectionUnit will use connectionBuilder to get a brand new Connection if toConnect is nullptr
    // Connection builder
    function<sp<ClientConnection>()> connectionBuilder;

    // Destination adress
    string address = "";
    // Destination port
    int port = -1;
}; 

#endif