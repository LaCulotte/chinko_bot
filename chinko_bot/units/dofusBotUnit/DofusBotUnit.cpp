#include "DofusBotUnit.h"

int DofusBotUnit::sendPacket(sp<ConnectionMessage> message, int connectionId) {

    if(connectionUnitId == -1) {
        connectionUnitId = getMessageInterfaceOutId<ConnectionUnit>();
        if(connectionUnitId == -1) {
            Logger::write("Cannot send packet : the is no ConnectionUnit linked to the current DofusBotUnit", LOG_ERROR);
            return -1;
        }
    }

    sp<SendPacketRequestMessage> sendPacketRequest(new SendPacketRequestMessage(message, connectionId));

    sendPacketRequest->packetId = lastPacketId;

    if(!sendMessage(sendPacketRequest, connectionUnitId)) {
        Logger::write("Could not send packet : could not send request to the ConnectionUnit", LOG_ERROR);
        return -1;
    }

    return lastPacketId++;
}