#include "SwitchContextFrame.h"
#include "Pathfinding.h"
#include "GameRolePlayCharacterInformations.h"

bool SwitchContextFrame::computeMessage(sp<Message> message, int srcId) {

    sp<GameContextCreateMessage> gccMsg;

    switch (message->getId())
    {
    case BeginGameContextRequestMessage::protocolId:
        // Requests the beginning of the GameContext building
        sendGameContextCreateRequestMessage();
        break;
    
    case SendPacketSuccessMessage::protocolId:
        // Handles SendPacketSuccessMessage
        if(!handleSendPacketSuccessMessage(dynamic_pointer_cast<SendPacketSuccessMessage>(message)))
            return false;
        
        break;

    case SendPacketFailureMessage::protocolId:
        // Handles SendPacketFailureMessage
        if(!handleSendPacketFailureMessage(dynamic_pointer_cast<SendPacketFailureMessage>(message)))
            return false;
        
        break;

    case GameContextCreateMessage::protocolId:
        // Adds frames according to the context to be created
        gccMsg = dynamic_pointer_cast<GameContextCreateMessage>(message);
        if(gccMsg->context == GameContextEnum::Roleplay) {
            Logger::write("Creating Roleplay context.", LOG_INFO);
            dofusBotParent->addFrame(make_shared<RoleplayContextFrame>());
            dofusBotParent->removeFrame(this);
        } else if(gccMsg->context == GameContextEnum::Fight) {
            Logger::write("Building Fight context.", LOG_INFO);
            dofusBotParent->addFrame(make_shared<FightContextFrame>());
            dofusBotParent->addFrame(make_shared<FightActionFrame>());
            dofusBotParent->removeFrame(this);
        } else {
            Logger::write("Context to build (" + to_string(gccMsg->context) + ") is unknown. No context will be built.", LOG_ERROR);
        }

        dofusBotParent->resetPlayedCharacter();
        break;

    case GameContextDestroyMessage::protocolId:
        Logger::write("Received GameContextDestroyMessage : no context to destroy.", LOG_INFO);
        break;

    default:
        return false;
    }    
    
    return true;
}

bool SwitchContextFrame::handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) {
    // Checks if the message was sent by this frame
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    // If so, gets the mapped message id
    int messageId = it->second;

    // Logs what message has been sent and changes Frame's state if needed
    switch (messageId)
    {
    case GameContextCreateRequestMessage::protocolId:
        Logger::write("GameContextCreateRequestMessage sent.", LOG_INFO);
        break;
    
    default:
        Logger::write("Message of id " + to_string(messageId) + " was successfully sent.", LOG_INFO);
        break;
    }

    packetId_to_messageId.erase(it);

    return true;
}

bool SwitchContextFrame::handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) {
    // Checks if the message was sent by this frame
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    // If so, gets the mapped message id
    int messageId = it->second;

    // Logs what message could not be sent and kills bot if needed
    switch (messageId)
    {
    case GameContextCreateRequestMessage::protocolId:
        Logger::write("GameContextCreateRequestMessage could not be sent.", LOG_WARNING);
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

bool SwitchContextFrame::sendGameContextCreateRequestMessage(){
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