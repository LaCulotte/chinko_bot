#ifndef SENDPACKET_SUCCESS_MESSAGE_H
#define SENDPACKET_SUCCESS_MESSAGE_H

#include "Message.h"

// Used to tell that the requested packet was successfuly sent
class SendPacketSuccessMessage : public Message {
public:
    // Constructor
    SendPacketSuccessMessage() {};
    // Copy construtor
    SendPacketSuccessMessage(const SendPacketSuccessMessage& other) = default;

    // Copy operator
    virtual SendPacketSuccessMessage& operator=(const SendPacketSuccessMessage& other) = default;
    // Destructor
    virtual ~SendPacketSuccessMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; }

    // Message's protocol Id
    static const unsigned int protocolId = 611;
};

#endif