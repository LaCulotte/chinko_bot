#include "CharacterSelectionFrame.h"

bool CharacterSelectionFrame::setParent(MessagingUnit* parent) {
    this->dofusBotParent = dynamic_cast<DofusBotUnit *>(parent); 
    if(dofusBotParent){
        this->parent = parent;
        return true;
    }

    return false;
}

bool CharacterSelectionFrame::computeMessage(sp<Message> message, int srcId) {

    sp<CharactersListRequestMessage> clrMsg;
    sp<UnknownDofusMessage> udMsg;
    int apiUnitId;

    switch (message->getId()) {
    case BeginCharacterSelectionMessage::protocolId:
        if(currentState == csf_idle) {

            clrMsg = make_shared<CharactersListRequestMessage>();
            if(parent->sendMessage(make_shared<SendPacketRequestMessage>(clrMsg, dofusBotParent->gameServerInfos.connectionId), dofusBotParent->connectionUnitId)) {
                currentState = snd_CharactersListRequestMessage;   
            } else {
                Logger::write("Cannot send message to connectionUnit", LOG_ERROR);
                // TODO : reset
            }

        } else {
            Logger::write("Tried to begin character selection while it was already started.", LOG_WARNING);
        }
        break;

    case SendPacketSuccessMessage::protocolId:
        if(handleSendPacketSuccessMessage(dynamic_pointer_cast<SendPacketSuccessMessage>(message)))
            break;
        
        return false;

    case SendPacketFailureMessage::protocolId:
        if(handleSendPacketFailureMessage(dynamic_pointer_cast<SendPacketFailureMessage>(message)))
            break;
        
        return false;

    case CharactersListMessage::protocolId:
    case BasicCharactersListMessage::protocolId:
        if(currentState == rcv_CharactersListMessage) {
            apiUnitId = parent->getMessageInterfaceOutId<APIUnit>();
            if(apiUnitId != -1) {
                parent->sendMessage(message, apiUnitId);
            } else {
                Logger::write("No APIUnit : cannot select character", LOG_ERROR);
            }
        } else {
            Logger::write("Received CharactersListMessage when not supposed to.", LOG_ERROR);
        }

        break;

    case CharacterSelectionMessage::protocolId:
        if(parent->sendMessage(make_shared<SendPacketRequestMessage>(dynamic_pointer_cast<ConnectionMessage>(message), dofusBotParent->gameServerInfos.connectionId), dofusBotParent->connectionUnitId)) {
            currentState = snd_CharacterSelectionMessage;
        } else {
            Logger::write("Cannot send message to connectionUnit", LOG_ERROR);
            // TODO : reset
        }
        break;

    default:
        return false;
    }

    return true;
}

bool CharacterSelectionFrame::handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) {
    switch (currentState)
    {
    case snd_CharactersListRequestMessage:
        Logger::write("CharactersListRequestMessage sent.", LOG_INFO);
        currentState = rcv_CharactersListMessage;
        break;
    
    case snd_CharacterSelectionMessage:
        Logger::write("CharactersSelectionMessage sent.", LOG_INFO);
        break;
    
    default:
        return false;
    }
    
    return true;
}

bool CharacterSelectionFrame::handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) {
    switch (currentState)
    {
    case snd_CharactersListRequestMessage:
        Logger::write("Failed to send CharactersListRequestMessage.", LOG_ERROR);
        // TODO : reset
        break;
    
    case snd_CharacterSelectionMessage:
        Logger::write("Failed to send CharacterSelectionMessage.", LOG_ERROR);
        // TODO : reset
        break;
    
    default:
        return false;
    }
    
    return true;
}