#ifndef PONG_MESSAGE_H
#define PONG_MESSAGE_H

#include "Message.h"

// Echo to PingMessage
class PongMessage : public Message {
public : 
    virtual unsigned int getId() override { return protocolId; };
    static const unsigned int protocolId = 601;
};

#endif