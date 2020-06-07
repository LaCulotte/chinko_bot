#ifndef CONNECTION_FAILURE_MESSAGE_H
#define CONNECTION_FAILURE_MESSAGE_H

#include "Message.h"

// Used to tell that the requested packet was not sent, with a reason defaulted at "Fail"
class ConnectionFailureMessage : public Message {
public:
    // Constructor
    ConnectionFailureMessage() {};
    // Constructor with reason setter
    ConnectionFailureMessage(string reason) { this->reason = reason; };
    // Copy construtor
    ConnectionFailureMessage(const ConnectionFailureMessage& other) = default;


    // Copy operator
    virtual ConnectionFailureMessage& operator=(const ConnectionFailureMessage& other) = default;
    // Destructor
    virtual ~ConnectionFailureMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; }
    // Message's protocol Id
    static const unsigned int protocolId = 615;

    // Reason that the packet send was not successful
    string reason = "Fail";
};

#endif