#ifndef BASIC_DOFUSBOT_FRAME_H
#define BASIC_DOFUSBOT_FRAME_H

#include "Frame.h"

#include "UnknownDofusMessage.h"

class BasicDofusBotFrame : public Frame {
public: 
    // Constructor
    BasicDofusBotFrame() : Frame() {};
    // Copy constructor
    BasicDofusBotFrame(const BasicDofusBotFrame& other) = default;

    // Copy operator
    BasicDofusBotFrame& operator=(const BasicDofusBotFrame& other) = default;
    // Destructor
    ~BasicDofusBotFrame() = default;

    virtual bool computeMessage(sp<Message> message, int srcId) override;
};

#endif