#ifndef BASIC_DOFUSBOT_FRAME_H
#define BASIC_DOFUSBOT_FRAME_H

#include "PacketSendingDofusBotFrame.h"

#include "DofusBotUnit.h"

#include "SendPacketRequestMessage.h"
#include "SendPacketSuccessMessage.h"
#include "SendPacketFailureMessage.h"

#include "UnknownDofusMessage.h"
#include "SequenceNumberRequestMessage.h"
#include "SequenceNumberMessage.h"

class BasicDofusBotFrame : public PacketSendingDofusBotFrame {
public: 
    // Constructor
    BasicDofusBotFrame() : PacketSendingDofusBotFrame() {};
    // Copy constructor
    BasicDofusBotFrame(const BasicDofusBotFrame& other) = default;

    // Copy operator
    BasicDofusBotFrame& operator=(const BasicDofusBotFrame& other) = default;
    // Destructor
    ~BasicDofusBotFrame() = default;

    virtual bool computeMessage(sp<Message> message, int srcId) override;

    int sequenceNumber = 0;

protected:
    bool handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) override;
    bool handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) override;

    bool sendSequenceNumberMessage();
};

#endif