#ifndef SENDPACKET_FAILURE_MESSAGE_H
#define SENDPACKET_FAILURE_MESSAGE_H

#include "Message.h"

// Used to tell that the requested packet was not sent, with a reason defaulted at "Fail"
class SendPacketFailureMessage : public Message {
public:
    // Constructor
    SendPacketFailureMessage() {};
    // Constructor with packetId initilization
    SendPacketFailureMessage(int packetId) { this->packetId = packetId; };
    // Constructor with reason initialization
    SendPacketFailureMessage(string reason) { this->reason = reason; };
    // Constructor with reason and packetId initialization
    SendPacketFailureMessage(string reason, int packetId) { this->reason = reason; this->packetId = packetId; };
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
    // Id of the packet that could not be sent
    int packetId = -1;
};

#endif