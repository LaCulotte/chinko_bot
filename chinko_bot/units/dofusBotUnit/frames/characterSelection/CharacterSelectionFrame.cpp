#include "CharacterSelectionFrame.h"

#include "CharacterUpdatesFrame.h"

#include "APIClientDisconnectedMessage.h"

#include "CharacterSelectionSuccessMessage.h"
#include "CharacterSelectionFailureMessage.h"


bool CharacterSelectionFrame::computeMessage(sp<Message> message, int srcId) {

    sp<CharactersListRequestMessage> clrMsg;
    sp<UnknownDofusMessage> udMsg;
    
    sp<CharacterSelectionMessage> csMsg;
    sp<CharacterSelectedSuccessMessage> cssMsg;


    switch (message->getId()) {
    case BeginCharacterSelectionMessage::protocolId:
        // This message request the beginning of the character selection process
        if(currentState == csf_idle) {
            // Sends the characters' list request 
            if(sendCharactersListRequestMessage())
                currentState = snd_CharactersListRequestMessage;   

        } else {
            Logger::write("Tried to begin character selection while it was already started.", LOG_WARNING);
        }
        break;

    case SendPacketSuccessMessage::protocolId:
        // Handles SendPacketSuccessMessage
        if(handleSendPacketSuccessMessage(dynamic_pointer_cast<SendPacketSuccessMessage>(message)))
            break;
        
        return false;

    case SendPacketFailureMessage::protocolId:
        // Handles SendPacketFailureMessage
        if(handleSendPacketFailureMessage(dynamic_pointer_cast<SendPacketFailureMessage>(message)))
            break;
        
        return false;

    case CharactersListMessage::protocolId:
    case BasicCharactersListMessage::protocolId:
        // Receive the characters' list
        if(currentState == rcv_CharactersListMessage) {
            // Asks for the APIUnit's id
            // apiUnitId = parent->getMessageInterfaceOutId<APIUnit>();
            if(dofusBotParent->getAPIUnitId() != -1) {
                // Sends the character list to the APIUnit
                sp<BasicCharactersListMessage> bclMsg = dynamic_pointer_cast<BasicCharactersListMessage>(message);
                sp<QueryCharacterSelectionMessage> qcsMsg = make_shared<QueryCharacterSelectionMessage>(bclMsg->characters);
                parent->sendMessage(qcsMsg, dofusBotParent->getAPIUnitId());
            } else {
                // If there is not APIUnit, logs it and kills the bot
                Logger::write("No APIUnit : cannot select character", LOG_ERROR);
                this->killBot();
            }
        } else {
            Logger::write("Received CharactersListMessage when not supposed to.", LOG_WARNING);
        }

        break;

    case CharacterSelectionMessage::protocolId:
        // Character Selection from the APIUnit
        // Relay it to the GameServer
        if(sendCharacterSelectionMessage(dynamic_pointer_cast<CharacterSelectionMessage>(message)))
            currentState = snd_CharacterSelectionMessage;
        break;
    
    case CharacterSelectedSuccessMessage::protocolId:
        // Character selection was successful
        if(currentState == rcv_CharacterSelectionResultMessage) {
            // Logs it
            cssMsg = dynamic_pointer_cast<CharacterSelectedSuccessMessage>(message);
            currentState = rcv_CharacterLoadingCompleteMessage;
            Logger::write("Successfully selected " + cssMsg->infos.name, LOG_INFO);
            dofusBotParent->sendMessage(make_shared<CharacterSelectionSuccessMessage>(cssMsg->infos.name), dofusBotParent->getAPIUnitId());
            
            dofusBotParent->playedCharacter = make_shared<RoleplayCharacterData>();
            dofusBotParent->playedCharacter->contextualId = cssMsg->infos.id;
            // dofusBotParent->playerId = cssMsg->infos.id;
            
            dofusBotParent->characterManager->setId(cssMsg->infos.id);
            dofusBotParent->characterManager->setName(cssMsg->infos.name);
            dofusBotParent->characterManager->setLevel(cssMsg->infos.level);
            dofusBotParent->characterManager->setBreed(cssMsg->infos.breed);
            dofusBotParent->characterManager->setSex(cssMsg->infos.sex);

            // Sends ClientKeyMessage with a 'hash' at the end 
            if(!sendClientKeyMessageWithHash()) {
                this->killBot();
            } else {
                parent->addFrame(make_shared<CharacterUpdatesFrame>());
                dofusBotParent->setConnectedToGameServer();
            }
        } else {
            Logger::write("Received CharacterSelectedSuccessMessage when not supposed to.", LOG_WARNING);
        }
        break;

    case CharacterSelectedErrorMessage::protocolId:
        // Character selection was unsuccessful
        if(currentState == rcv_CharacterSelectionResultMessage) {
            // TODO : Mettre ca en fonction comme un reset ?
            // Retry the character selection
            currentState = csf_idle;
            parent->sendSelfMessage(make_shared<BeginCharacterSelectionMessage>());
            Logger::write("Error while selecting requested character. Please select a valid character.", LOG_WARNING);
            dofusBotParent->sendMessage(make_shared<CharacterSelectionFailureMessage>(), dofusBotParent->getAPIUnitId());
        } else {
            Logger::write("Received CharacterSelectedErrorMessage when not supposed to.", LOG_WARNING);
        }
        break;

    case CharacterLoadingCompleteMessage::protocolId:
        // Character has been fully loaded
        if(currentState == rcv_CharacterLoadingCompleteMessage) {
            // Logs it
            currentState = csf_idle;
            Logger::write("Character loading complete !", LOG_INFO);

            dofusBotParent->characterManager->loadingFinished();
            // TODO : mettre ca en fonction?
            // Delete this Frame (self destruct) and introduces a brand new SwitchContextFrame
            dofusBotParent->addFrame(make_shared<SwitchContextFrame>());
            dofusBotParent->removeFrame(this);
            // Requests GameContext building
            dofusBotParent->sendSelfMessage(make_shared<BeginGameContextRequestMessage>());

        } else {
            Logger::write("Received CharacterLoadingCompleteMessage when not supposed to.", LOG_WARNING);
        }
        break;        

    case APIClientDisconnectedMessage::protocolId:
        Logger::write("API client disconnected during authentification : bot will be reset.", LOG_WARNING);

        dofusBotParent->resetNextTick();
        break;

    default:
        return false;
    }

    return true;
}

bool CharacterSelectionFrame::handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) {
    // Checks if the message was sent by this frame
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    // If so, gets the mapped message id
    int messageId = it->second;

    // Logs what message has been sent and changes Frame's state if needed
    switch (messageId)
    {
    case CharactersListRequestMessage::protocolId:
        if(currentState == snd_CharactersListRequestMessage) {
            Logger::write("CharactersListRequestMessage sent.", LOG_INFO);
            currentState = rcv_CharactersListMessage;
        } else {
            Logger::write("CharacterListRequestMessage was sent but was not supposed to.", LOG_WARNING);
        }
        break;

    case CharacterSelectionMessage::protocolId:
        if(currentState == snd_CharacterSelectionMessage) {
            Logger::write("CharactersSelectionMessage sent.", LOG_INFO);
            currentState = rcv_CharacterSelectionResultMessage;
        } else {
            Logger::write("CharacterListRequestMessage was sent but was not supposed to.", LOG_WARNING);
        }
        break;

    case ClientKeyMessage::protocolId:
        Logger::write("ClientKeyMessage with hash sent.", LOG_INFO);
        break;

    default:
        Logger::write("Message of id " + to_string(messageId) + " was successfully sent.", LOG_INFO);
        break;
    }

    packetId_to_messageId.erase(it);

    return true;
}

bool CharacterSelectionFrame::handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) {
    // Checks if the message was sent by this frame
   auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    // If so, gets the mapped message id
    int messageId = it->second;

    // Logs what message could not be sent and kills bot if needed
    switch (messageId)
    {
    case CharactersListRequestMessage::protocolId:
        if(currentState == snd_CharactersListRequestMessage) {
            Logger::write("CharactersListRequestMessage could not be sent.", LOG_WARNING);
            this->killBot();
        } else {
            Logger::write("CharacterListRequestMessage could not be sent but was not supposed to.", LOG_WARNING);
        }
        break;

    case CharacterSelectionMessage::protocolId:
        if(currentState == snd_CharacterSelectionMessage) {
            Logger::write("CharactersSelectionMessage could not be sent.", LOG_WARNING);
            this->killBot();
        } else {
            Logger::write("CharacterListRequestMessage could not be sent but was not supposed to.", LOG_WARNING);
        }
        break;

    case ClientKeyMessage::protocolId:
        Logger::write("ClientKeyMessage with a hash could not be sent", LOG_WARNING);
            this->killBot();
        break;

    default:
        Logger::write("Message of id " + to_string(messageId) + " could not be sent.", LOG_WARNING);
        break;
    }

    packetId_to_messageId.erase(it);

    return true;
}

bool CharacterSelectionFrame::sendClientKeyMessageWithHash(){
    sp<ClientKeyMessage> ckMsg(new ClientKeyMessage(true));

    if(!ckMsg) {
        Logger::write("Cannot generate ClientKeyMessage", LOG_ERROR);
        this->killBot();
        return false;
    }
    
    if(!sendPacket(ckMsg, dofusBotParent->gameServerInfos.connectionId)) {
        Logger::write("Cannot send ClientKeyMessage with a hash.", LOG_ERROR);
        this->killBot();
        return false;
    }

    return true;
}

bool CharacterSelectionFrame::sendCharactersListRequestMessage() {
    sp<CharactersListRequestMessage> clrMsg = make_shared<CharactersListRequestMessage>();

    if(!clrMsg) {
        Logger::write("Cannot build CharactersListRequestMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }

    if(!sendPacket(clrMsg, dofusBotParent->gameServerInfos.connectionId)) {
        Logger::write("Cannot send message to connectionUnit", LOG_ERROR);
        this->killBot();
        return false;
    }

    return true;
}

bool CharacterSelectionFrame::sendCharacterSelectionMessage(sp<CharacterSelectionMessage> csMsg) {
    if(!csMsg) {
        Logger::write("Cannot build CharacterSelectionMessage.", LOG_ERROR);
        this->killBot();
        return false;
    } 

    if(!sendPacket(csMsg, dofusBotParent->gameServerInfos.connectionId)) {
        Logger::write("Cannot send CharacterSelectionMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }

    return true;
}