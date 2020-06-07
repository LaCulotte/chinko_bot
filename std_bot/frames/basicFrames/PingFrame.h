#ifndef PINGFRAME_H
#define PINGFRAME_H

#include "Frame.h"
#include "PingMessage.h"
#include "PongMessage.h"

// Frame for Ping/Pong message
class PingFrame : public Frame {
public:

    // 'Acts' according to the message. SrcKey is there to indentify the message's source (sender)
    virtual bool computeMessage(sp<Message> message, int srcId) override;
};

#endif