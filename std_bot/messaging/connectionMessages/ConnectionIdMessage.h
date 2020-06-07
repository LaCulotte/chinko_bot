#ifndef CONNECTIONIDMESSAGE
#define CONNECTIONIDMESSAGE

#include "Message.h"
#include "Connection.h"
#include <functional>

class ConnectionIdMessage : public Message {
public:
    // Contructor
    ConnectionIdMessage() {};
    // Constructor; Sets returning ids
    ConnectionIdMessage(vector<int> ids) { this->ids = ids; };
    // Copy constuctor
    ConnectionIdMessage(const ConnectionIdMessage& other) = default;

    // Copy operator
    virtual ConnectionIdMessage& operator=(const ConnectionIdMessage& other) = default;
    // Destructor
    virtual ~ConnectionIdMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; };
    // Message's protocol Id
    static const unsigned int protocolId = 617;

    // Ids of the connections asked in a ConnectionIdGetMessage
    vector<int> ids;
};

#endif