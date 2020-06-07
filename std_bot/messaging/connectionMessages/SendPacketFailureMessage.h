#ifndef SENDPACKET_FAILURE_MESSAGE_H
#define SENDPACKET_FAILURE_MESSAGE_H

#include "Message.h"

// Used to tell that the requested packet was not sent, with a reason defaulted at "Fail"
class SendPacketFailureMessage : public Message {
public:
    // Constructor
    SendPacketFailureMessage() {};
    // Constructor with reason setter
    SendPacketFailureMessage(string reason) { this->reason = reason; };
    // Copy construtor
    SendPacketFailureMessage(const SendPacketFailureMessage& other) = default;


    // Copy operator
    virtual SendPacketFailureMessage& operator=(const SendPacketFailureMessage& other) = default;
    // Destructor
    virtual ~SendPacketFailureMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; }
    // Message's protocol Id
    static const unsigned int protocolId = 612;

    // Reason that the packet send was not successful
    string reason = "Fail";
};

#endif