#ifndef BASIC_DOFUSBOT_FRAME_H
#define BASIC_DOFUSBOT_FRAME_H

#include "Frame.h"

#include "DofusBotUnit.h"

#include "SendPacketRequestMessage.h"
#include "SendPacketSuccessMessage.h"
#include "SendPacketFailureMessage.h"

#include "UnknownDofusMessage.h"
#include "SequenceNumberRequestMessage.h"
#include "SequenceNumberMessage.h"

enum BasicDofusBotFrameState {
    bdb_idle,
    snd_SequenceNumberMessage
};

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

    virtual bool setParent(MessagingUnit* parent) override;

    int sequenceNumber = 0;

    DofusBotUnit* dofusBotParent = nullptr;

protected:
    BasicDofusBotFrameState currentState = bdb_idle;

    bool handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message);
    bool handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message);

};

#endif