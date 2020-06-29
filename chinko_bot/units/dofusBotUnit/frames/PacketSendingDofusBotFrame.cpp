#include "PacketSendingDofusBotFrame.h"

bool PacketSendingDofusBotFrame::sendPacket(sp<ConnectionMessage> message, int connectionId) {
    if(!dofusBotParent) {
        Logger::write("Cannot send packet : No DofusBotUnit is linked to the frame", LOG_ERROR);
        return false;
    }

    int packetId = dofusBotParent->sendPacket(message, connectionId);

    if(packetId == -1) {
        return false;
    } else {
        packetId_to_messageId[packetId] = message->getId();
        return true;
    }
}

bool PacketSendingDofusBotFrame::handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) {
    if(packetId_to_messageId.find(message->packetId) != packetId_to_messageId.end()) {
        packetId_to_messageId.erase(message->packetId);
        return true;
    } else {
        return false;
    }
}

bool PacketSendingDofusBotFrame::handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) {
    if(packetId_to_messageId.find(message->packetId) != packetId_to_messageId.end()) {
        packetId_to_messageId.erase(message->packetId);
        return true;
    } else {
        return false;
    }
}