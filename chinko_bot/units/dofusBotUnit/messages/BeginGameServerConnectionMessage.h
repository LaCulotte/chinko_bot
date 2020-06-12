#ifndef BEGIN_GAMESERVERCONNECTION_MESSAGE_H
#define BEGIN_GAMESERVERCONNECTION_MESSAGE_H

#include "Message.h"
#include "SelectedServerDataMessage.h"

class BeginGameServerConnectionMessage : public Message {
public:
    // Constructor
    BeginGameServerConnectionMessage() {};
    // Constructor with SelectedServerDataMessage initialization
    BeginGameServerConnectionMessage(sp<SelectedServerDataMessage> ssdMsg) { this->ssdMsg = ssdMsg; };
    // Copy constructor
    BeginGameServerConnectionMessage(const BeginGameServerConnectionMessage& other) = default;

    // Copy operator
    BeginGameServerConnectionMessage& operator=(const BeginGameServerConnectionMessage& other) = default;
    // Destructor
    ~BeginGameServerConnectionMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; };
    // Message's protocol Id
    static const unsigned int protocolId = 641;

    sp<SelectedServerDataMessage> ssdMsg;
};

#endif