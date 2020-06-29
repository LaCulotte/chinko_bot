#ifndef SENDPACKETMESSAGE_H
#define SENDPACKETMESSAGE_H

#include "ConnectionMessage.h"

// Used to tell the ConnectionUnit to send a message
class SendPacketRequestMessage : public Message {
public:
    // Contructor
    SendPacketRequestMessage() {};
    // Constructor
    SendPacketRequestMessage(sp<ConnectionMessage> message) { this->message = message; };
    // Constructor
    SendPacketRequestMessage(sp<ConnectionMessage> message, int connectionId) { this->message = message; this->connectionId = connectionId; };
    // Copy constuctor
    SendPacketRequestMessage(const SendPacketRequestMessage& other) { message = make_shared<ConnectionMessage>(); *message = *other.message; };

    // Copy operator
    virtual SendPacketRequestMessage& operator=(const SendPacketRequestMessage& other) { message = make_shared<ConnectionMessage>(); *message = *other.message; return *this; };
    // Destructor
    virtual ~SendPacketRequestMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; };
    // Message's protocol Id
    static const unsigned int protocolId = 610;

    // Packet to send through the ConnectionUnit
    sp<ConnectionMessage> message; 
    // Unique (if != -1) id to identify the packet to be sent
    int packetId = -1;

    // Connection through witch the packet will be sent
    int connectionId = -1;
};

#endif