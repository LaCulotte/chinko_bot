#ifndef PACKETSENDING_DOFUSBOT_FRAME_H
#define PACKETSENDING_DOFUSBOT_FRAME_H

#include "PacketHandlingDofusBotFrame.h"

#include <unordered_map>

// Frame that saves and map a sent packet id to a message id, in order to know which messages could be sent and which could not 
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
    // Maps packet's id to the message id
    unordered_map<int, int> packetId_to_messageId;
    // Sends a packet
    virtual bool sendPacket(sp<ConnectionMessage> message, int connectionId);

    // Very basic example of SendPacketResponse handling. To override completely
    virtual bool handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) override;
    virtual bool handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) override;

};

#endif