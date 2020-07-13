#include "ContextFrame.h"

bool ContextFrame::computeMessage(sp<Message> message, int srcId) {

    sp<GameContextCreateMessage> gccMsg;
    sp<CurrentMapMessage> ccMsg;

    switch (message->getId())
    {
    case BeginGameContextRequestMessage::protocolId:
        sendGameContextCreateRequestMessage();
        break;
    
    case SendPacketSuccessMessage::protocolId:
        if(!handleSendPacketSuccessMessage(dynamic_pointer_cast<SendPacketSuccessMessage>(message)))
            return false;
        
        break;

    case SendPacketFailureMessage::protocolId:
        if(!handleSendPacketFailureMessage(dynamic_pointer_cast<SendPacketFailureMessage>(message)))
            return false;
        
        break;

    case GameContextCreateMessage::protocolId:
        gccMsg = dynamic_pointer_cast<GameContextCreateMessage>(message);
        Logger::write("Received GameContextCreateMessage. Context : " + to_string(gccMsg->context), LOG_INFO);
        break;

    case CurrentMapMessage::protocolId:
        ccMsg = dynamic_pointer_cast<CurrentMapMessage>(message);
        Logger::write("Received CurrentMapMessage.", LOG_INFO);
        Logger::write("Map id : " + to_string(ccMsg->mapId) + ". Map key : " + ccMsg->mapKey, LOG_INFO);

        sendMapInformationsRequestMessage(ccMsg->mapId);
        break;

    default:
        return false;
    }    
    
    return true;
}

bool ContextFrame::handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) {
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    int messageId = it->second;

    switch (messageId)
    {
    case GameContextCreateRequestMessage::protocolId:
        Logger::write("GameContextCreateRequestMessage sent.", LOG_INFO);
        break;

    case MapInformationsRequestMessage::protocolId:
        Logger::write("MapInformationsRequestMessage sent.", LOG_INFO);
        break;
    
    default:
        Logger::write("Message of id " + to_string(messageId) + " was successfully sent.", LOG_INFO);
        break;
    }

    packetId_to_messageId.erase(it);

    return true;
}

bool ContextFrame::handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) {
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    int messageId = it->second;

    switch (messageId)
    {
    case GameContextCreateRequestMessage::protocolId:
        Logger::write("GameContextCreateRequestMessage could not be sent.", LOG_WARNING);
        // A voir si bot kill
        break;

    case MapInformationsRequestMessage::protocolId:
        Logger::write("MapInformationsRequestMessage could not be sent.", LOG_WARNING);
        // A voir si bot kill
        break;
    
    default:
        Logger::write("Message of id " + to_string(messageId) + " was could not be sent. Reason : " + message->reason, LOG_WARNING);
        // A voir si bot kill
        break;
    }

    packetId_to_messageId.erase(it);

    return true;
}

bool ContextFrame::sendGameContextCreateRequestMessage(){
    sp<GameContextCreateRequestMessage> gccrMsg(new GameContextCreateRequestMessage());

    if(!gccrMsg) {
        Logger::write("Cannot build GameContextCreateRequestMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }

    if(!sendPacket(gccrMsg, dofusBotParent->gameServerInfos.connectionId)) {
        Logger::write("Cannot send GameContextCreateRequestMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }

    return true;
}

bool ContextFrame::sendMapInformationsRequestMessage(double mapId){
    sp<MapInformationsRequestMessage> mirMsg(new MapInformationsRequestMessage(mapId));

    if(!mirMsg) {
        Logger::write("Cannot build MapInformationsRequestMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }

    if(!sendPacket(mirMsg, dofusBotParent->gameServerInfos.connectionId)) {
        Logger::write("Cannot send MapInformationRequestMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }

    return true;
}