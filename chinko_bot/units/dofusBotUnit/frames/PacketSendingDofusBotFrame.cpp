#include "PacketSendingDofusBotFrame.h"

bool PacketSendingDofusBotFrame::sendPacket(sp<ConnectionMessage> message, int connectionId) {
    // Checks if a parent have been attached
    if(!dofusBotParent) {
        Logger::write("Cannot send packet : No DofusBotUnit is linked to the frame", LOG_ERROR);
        return false;
    }

    // Send Packet and retreive packet's id
    int packetId = dofusBotParent->sendPacket(message, connectionId);

    if(packetId == -1) {
        // If packet's id is -1, the packet could not be sent
        return false;
    } else {
        // Maps the packet'd id to the message's id
        packetId_to_messageId[packetId] = message->getId();
        return true;
    }
}

bool PacketSendingDofusBotFrame::handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) {
    // Checks if the packet has been sent by this frame.
    if(packetId_to_messageId.find(message->packetId) != packetId_to_messageId.end()) {
        // If so, deletes the mapping and return that the message has been computed.
        packetId_to_messageId.erase(message->packetId);
        return true;
    } else {
        return false;
    }
}

bool PacketSendingDofusBotFrame::handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) {
    // Checks if the packet has been sent by this frame.
    if(packetId_to_messageId.find(message->packetId) != packetId_to_messageId.end()) {
        // If so, deletes the mapping and return that the message has been computed.
        packetId_to_messageId.erase(message->packetId);
        return true;
    } else {
        return false;
    }
}