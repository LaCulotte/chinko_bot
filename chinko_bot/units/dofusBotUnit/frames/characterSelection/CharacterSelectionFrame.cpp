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

    sp<CharacterSelectedSuccessMessage> cssMsg;

    sp<InventoryContentMessage> icMsg;
    sp<InventoryWeightMessage> iwMsg;
    sp<ShortcutBarContentMessage> sbcMsg;
    sp<JobExperienceMultiUpdateMessage> jemuMsg;
    sp<AlmanachCalendarDateMessage> acdMsg;
    sp<CharacterExperienceGainMessage> cegMsg;
    sp<SpellListMessage> slMsg;

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
            Logger::write("Received CharactersListMessage when not supposed to.", LOG_WARNING);
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
    
    case CharacterSelectedSuccessMessage::protocolId:
        if(currentState == rcv_CharacterSelectionResultMessage) {
            cssMsg = dynamic_pointer_cast<CharacterSelectedSuccessMessage>(message);
            currentState = rcv_CharacterLoadingCompleteMessage;
            Logger::write("Successfully selected " + cssMsg->infos.name, LOG_INFO);
        } else {
            Logger::write("Received CharacterSelectedSuccessMessage when not supposed to.", LOG_WARNING);
        }
        break;

    case CharacterSelectedErrorMessage::protocolId:
        if(currentState == rcv_CharacterSelectionResultMessage) {
            currentState = csf_idle;
            parent->sendSelfMessage(make_shared<BeginCharacterSelectionMessage>());
            Logger::write("Error while selecting requested character. Please select a valid character.", LOG_WARNING);
        } else {
            Logger::write("Received CharacterSelectedErrorMessage when not supposed to.", LOG_WARNING);
        }
        break;

    case CharacterLoadingCompleteMessage::protocolId:
        if(currentState == rcv_CharacterLoadingCompleteMessage) {
            currentState = csf_idle;
            Logger::write("Character loading complete !", LOG_INFO);
        } else {
            Logger::write("Received CharacterLoadingCompleteMessage when not supposed to.", LOG_WARNING);
        }
        break;        

    // TODO : à enlever
    case InventoryContentMessage::protocolId:
        icMsg = dynamic_pointer_cast<InventoryContentMessage>(message);
        Logger::write("Received InventoryContentMessage", LOG_INFO);
        break;

    // TODO : à enlever
    case ShortcutBarContentMessage::protocolId:
        sbcMsg = dynamic_pointer_cast<ShortcutBarContentMessage>(message);
        Logger::write("Received ShortcutBarContentMessage", LOG_INFO);
        break;

    // TODO : à enlever
    case JobExperienceMultiUpdateMessage::protocolId:
        jemuMsg = dynamic_pointer_cast<JobExperienceMultiUpdateMessage>(message);
        Logger::write("Received JobExperienceMultiUpdateMessage", LOG_INFO);
        break;
    
    // TODO : à enlever
    case InventoryWeightMessage::protocolId:
        iwMsg = dynamic_pointer_cast<InventoryWeightMessage>(message);
        Logger::write("Received JobExperienceMultiUpdateMessage", LOG_INFO);
        Logger::write("Current weight : " + to_string(iwMsg->inventoryWeight) + "/" + to_string(iwMsg->maxWeight), LOG_INFO);
        break;

    // TODO : à enlever
    case AlmanachCalendarDateMessage::protocolId:
        acdMsg = dynamic_pointer_cast<AlmanachCalendarDateMessage>(message);
        Logger::write("Received AlmanachCalendarDateMessage", LOG_INFO);
        break;

    // TODO : à enlever
    case CharacterExperienceGainMessage::protocolId:
        cegMsg = dynamic_pointer_cast<CharacterExperienceGainMessage>(message);
        Logger::write("Received CharacterExperienceGainMessage", LOG_INFO);
        break;

    // TODO : à enlever
    case SpellListMessage::protocolId:
        slMsg = dynamic_pointer_cast<SpellListMessage>(message);
        Logger::write("Received SpellListMessage", LOG_INFO);
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
        currentState = rcv_CharacterSelectionResultMessage;
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