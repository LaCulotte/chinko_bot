#ifndef DISCONNECT_REQUEST_MESSAGE
#define DISCONNECT_REQUEST_MESSAGE

#include "Message.h"
#include "Connection.h"
#include <functional>

// Asks for the focus of one or multiple connections.
// In other words, it asks some connections to send the incoming messages to the sending MessagingUnit
class DisconnectRequestMessage : public Message {
public:
    // Contructor
    DisconnectRequestMessage() {};
    // Constructor; will diconnect the connection whose id is in 'connectionIds'
    DisconnectRequestMessage(vector<int> connectionIds) { this->connectionIds = connectionIds; };
    // Constructor; will disconnect from all the connections that make 'filter' return true
    DisconnectRequestMessage(function<bool(sp<Connection>)> filter) { this->filter = filter; };
    // Copy constuctor
    DisconnectRequestMessage(const DisconnectRequestMessage& other) = default;

    // Copy operator
    virtual DisconnectRequestMessage& operator=(const DisconnectRequestMessage& other) = default;
    // Destructor
    virtual ~DisconnectRequestMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; };
    // Message's protocol Id
    static const unsigned int protocolId = 621;

    // Ids of the connections to disconnect
    vector<int> connectionIds = {};
    /** Filter : diconnects from the connections that make 'filter' return true when passed as argument
     *  Will use the filter if connectionIds is empty
     */
    function<bool(sp<Connection>)> filter;

    // True if all the connections passing the filter should be disconnected
    bool all = false;
    // If 'all = false', the number of connections that should be disconnected
    int n = 1;
};

#endif