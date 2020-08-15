#include "DofusBotUnit.h"

int DofusBotUnit::sendPacket(sp<ConnectionMessage> message, int connectionId) {

    if(connectionUnitId == -1) {
        // Tries to get ConnectionUnit's id 
        connectionUnitId = getMessageInterfaceOutId<ConnectionUnit>();
        if(connectionUnitId == -1) {
            // Error if there is not ConnectionUnit linked to the bot 
            Logger::write("Cannot send packet : there is no ConnectionUnit linked to the current DofusBotUnit", LOG_ERROR);
            return -1;
        }
    }

    // Builds a SendPacketRequestMessage 
    sp<SendPacketRequestMessage> sendPacketRequest(new SendPacketRequestMessage(message, connectionId));

    // Sets the packet Id
    sendPacketRequest->packetId = lastPacketId;

    // Send the request to the ConnectionUnit
    if(!sendMessage(sendPacketRequest, connectionUnitId)) {
        Logger::write("Could not send packet : could not send request to the ConnectionUnit", LOG_ERROR);
        return -1;
    }

    return lastPacketId++;
}