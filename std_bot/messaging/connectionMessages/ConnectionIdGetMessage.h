#ifndef CONNECTIONID_GET_MESSAGE
#define CONNECTIONID_GET_MESSAGE

#include "Message.h"
#include "Connection.h"
#include <functional>

// Asks the ConnectionUnit to get the id of one or multiple connections
class ConnectionIdGetMessage : public Message {
public:
    // Contructor
    ConnectionIdGetMessage() {};
    // Constructor; Sets filter
    ConnectionIdGetMessage(function<bool(sp<Connection>)> filter) { this->filter = filter; };
    // Copy constuctor
    ConnectionIdGetMessage(const ConnectionIdGetMessage& other) = default;

    // Copy operator
    virtual ConnectionIdGetMessage& operator=(const ConnectionIdGetMessage& other) = default;
    // Destructor
    virtual ~ConnectionIdGetMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; };
    // Message's protocol Id
    static const unsigned int protocolId = 616;

    // Filter : will only return a connection only if the filter returns true with it as argument
    function<bool(sp<Connection>)> filter;

    // True if all the connections passing the filter should be returned
    bool all = false;
    // If 'all = false', the number of connections to return
    int n = 1;
};

#endif