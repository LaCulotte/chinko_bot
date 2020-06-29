#ifndef PACKETHANDLING_DOFUSBOT_FRAME_H
#define PACKETHANDLING_DOFUSBOT_FRAME_H

#include "DofusBotFrame.h"

#include "SendPacketSuccessMessage.h"
#include "SendPacketFailureMessage.h"

class PacketHandlingDofusBotFrame : public DofusBotFrame {
public:
    // Constructor
    PacketHandlingDofusBotFrame() : Frame() {};
    // Copy constructor
    PacketHandlingDofusBotFrame(const PacketHandlingDofusBotFrame& other) = default;

    // Copy operator
    PacketHandlingDofusBotFrame& operator=(const PacketHandlingDofusBotFrame& other) = default;
    // Destructor
    ~PacketHandlingDofusBotFrame() = default;

protected:
    virtual bool handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) = 0;
    virtual bool handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) = 0;
};

#endif