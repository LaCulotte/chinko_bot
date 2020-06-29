#ifndef PACKETSENDING_DOFUSBOT_FRAME_H
#define PACKETSENDING_DOFUSBOT_FRAME_H

#include "PacketHandlingDofusBotFrame.h"

#include <unordered_map>

class PacketSendingDofusBotFrame : public PacketHandlingDofusBotFrame {
public:
    // Constructor
    PacketSendingDofusBotFrame() : Frame() {};
    // Copy constructor
    PacketSendingDofusBotFrame(const PacketSendingDofusBotFrame& other) = default;

    // Copy operator
    PacketSendingDofusBotFrame& operator=(const PacketSendingDofusBotFrame& other) = default;
    // Destructor
    ~PacketSendingDofusBotFrame() = default;

protected:
    unordered_map<int, int> packetId_to_messageId;
    virtual bool sendPacket(sp<ConnectionMessage> message, int connectionId);

    // To override completely
    virtual bool handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) override;
    virtual bool handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) override;

};

#endif