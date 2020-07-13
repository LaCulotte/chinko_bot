#include "GameServerConnectionFrame.h"

bool GameServerConnectionFrame::computeMessage(sp<Message> message, int srcId) {
    sp<BeginGameServerConnectionMessage> bgscMsg;
    sp<ConnectionSuccessMessage> csMsg;
    sp<ConnectionFailureMessage> cfMsg;
    sp<BasicCharactersListMessage> bclMsg;

    sp<UnknownDofusMessage> udMsg;
    sp<ProtocolRequiredMessage> prMsg;

    switch (message->getId())
    {
    case BeginGameServerConnectionMessage::protocolId:
        if(currentState == gcsf_idle) {
            bgscMsg = dynamic_pointer_cast<BeginGameServerConnectionMessage>(message);

            if(!manager) {
                Logger::write("Cannot begin Game server connection if there is no AuthentificationManager.", LOG_ERROR);
                this->killBot();
                break;
            }

            serverAddress = bgscMsg->ssdMsg->address;
            serverPorts = bgscMsg->ssdMsg->ports;
            if(serverPorts.size() <= 0) {
                Logger::write("Cannot connect to the game server (" + serverAddress + ") : No port specified.", LOG_ERROR);
                // TODO : reset vers authentification
                break;
            }
            serverPorts_i = 0;
            
            if(!manager->connectGameServer(serverAddress, serverPorts[0])) {
                // TODO : reset vers authentification ou bot kill (pas de ticket client)
            } else {
                currentState = begin_GameServerConnection;
            }
        } else {
            Logger::write("Tried to begin the GameServer connection while it is already started.", LOG_WARNING);
        }

        break;
    
    case ConnectionSuccessMessage::protocolId:
        if(currentState == begin_GameServerConnection) {
            csMsg = dynamic_pointer_cast<ConnectionSuccessMessage>(message);

            dofusBotParent->gameServerInfos.connectionId = csMsg->connectionId;
            dofusBotParent->gameServerInfos.adress = serverAddress;
            
            currentState = rcv_HelloGameMessage;
            Logger::write("Connected to the game server : " + serverAddress, LOG_INFO);
            break;
        }

        return false;

    case ConnectionFailureMessage::protocolId:
        if(currentState == begin_GameServerConnection) {
            cfMsg = dynamic_pointer_cast<ConnectionFailureMessage>(message);

            Logger::write("Failed to connect to " + serverAddress + ":" + to_string(serverPorts[serverPorts_i]) + "; Reason : " + cfMsg->reason, LOG_WARNING);
            if(++serverPorts_i >= serverPorts.size()) {
                Logger::write("Cannot connect to the game server", LOG_ERROR);
                // TODO : reset authentification
                break;
            } else {
                Logger::write("Trying an next port", LOG_WARNING);
                if(!manager->connectGameServer(serverAddress, serverPorts[serverPorts_i])) {
                    // TODO : reset vers authentification
                }
            }
            break;
        }

        return false;

    case SendPacketSuccessMessage::protocolId:
        if(handleSendPacketSuccessMessage(dynamic_pointer_cast<SendPacketSuccessMessage>(message))) 
            break;

        return false;        

    case SendPacketFailureMessage::protocolId:
        if(handleSendPacketFailureMessage(dynamic_pointer_cast<SendPacketFailureMessage>(message))) 
            break;

        return false;        

    case ProtocolRequiredMessage::protocolId:
        prMsg = dynamic_pointer_cast<ProtocolRequiredMessage>(message);
        // TODO : refuser si mauvaise version
        Logger::write("ProtocolRequiredMessage received", LOG_INFO);
        Logger::write("Required version : " + to_string(prMsg->requiredVersion) + "; Current version : " + to_string(prMsg->currentVersion), LOG_INFO);
        break;

    case HelloGameMessage::protocolId:
        if(currentState == rcv_HelloGameMessage) {
            Logger::write("Received HelloGameMessage", LOG_INFO);

            if (sendAuthentificationTicketMessage())
                currentState = snd_AuthentificationTicketMessage;

        } else {
            Logger::write("Received HelloGameMessage when not supposed to.", LOG_WARNING);
        }

        break;

    case RawDataMessage::protocolId:
        if(currentState == rcv_RawDataMessage) {
            Logger::write("Received RawDataMessage", LOG_INFO);

            if(sendCheckIntegrityMessage())
                currentState = snd_CheckIntegrityMessage;

        } else {
            Logger::write("Received RawDataMessage when not supposed to.", LOG_WARNING);
        }
        break;

    // TODO : cas AuthentificationTicketRefusedMessage
    case AuthentificationTicketAcceptedMessage::protocolId:
        if(currentState == rcv_AuthentificationTicketResponseMessage) {
            Logger::write("Received AuthentificationTicketAcceptedMessage", LOG_INFO);

            sp<CharacterSelectionFrame> csFrame(new CharacterSelectionFrame());
            if(parent->addFrame(csFrame)) {
                parent->sendSelfMessage(make_shared<BeginCharacterSelectionMessage>());
                parent->removeFrame(this);
            } else {
                Logger::write("Could not add CharacterSelectionFrame to parent.", LOG_ERROR);
                this->killBot();
            }
            currentState = end_GameServerConnection;
        } else {
            Logger::write("Received AuthentificationTicketAcceptedMessage when not supposed to.", LOG_WARNING);
        }

        break;

    default:
        return false;
    }

    return true;
}

bool GameServerConnectionFrame::handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) {
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    int messageId = it->second;

    switch (messageId)
    {
    case AuthentificationTicketMessage::protocolId:
        if(currentState == snd_AuthentificationTicketMessage) {
            Logger::write("AuthentificationTicketMessage sent.", LOG_INFO);
            currentState = rcv_RawDataMessage;
        } else {
            Logger::write("AuthentificationTicketMessage sent but was not supposed to.", LOG_WARNING);
        } 
        break;
    
    case CheckIntegrityMessage::protocolId:
        if(currentState == snd_CheckIntegrityMessage) {
            Logger::write("CheckIntegrityMessage sent.", LOG_INFO);
            currentState = rcv_AuthentificationTicketResponseMessage;
        } else {
            Logger::write("AuthentificationTicketMessage sent but was not supposed to.", LOG_WARNING);
        }
        break;

    default:
        Logger::write("Message of id " + to_string(messageId) + " was sucessfully sent.", LOG_INFO);
        break;
    }

    packetId_to_messageId.erase(it);

   return true;
}

bool GameServerConnectionFrame::handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) {
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    int messageId = it->second;

    switch (messageId)
    {
    case AuthentificationTicketMessage::protocolId:
        if(currentState == snd_AuthentificationTicketMessage) {
            Logger::write("AuthentificationTicketMessage could not be sent. Reason : " + message->reason, LOG_WARNING);
            this->killBot();
        } else {
            Logger::write("AuthentificationTicketMessage could not be but was not supposed to. Reason : " + message->reason, LOG_WARNING);
        } 
        break;
    
    case CheckIntegrityMessage::protocolId:
        if(currentState == snd_CheckIntegrityMessage) {
            Logger::write("CheckIntegrityMessage could not be sent. Reason : " + message->reason, LOG_WARNING);
            this->killBot();
        } else {
            Logger::write("CheckIntegrityMessage could not be but was not supposed to. Reason : " + message->reason, LOG_WARNING);
        } 
        break;
    
    default:
        Logger::write("Could not send message of id : " + to_string(messageId), LOG_WARNING);
        break;
    }

    packetId_to_messageId.erase(it);

    return true;
}

bool GameServerConnectionFrame::sendAuthentificationTicketMessage() {
    sp<AuthentificationTicketMessage> atMsg = manager->generateAuthentificationTicketMessage();
    if(!atMsg) {
        Logger::write("Cannot generate AuthentificationTicketMessage", LOG_ERROR);
        this->killBot();
        return false;
    }
    if(!sendPacket(atMsg, dofusBotParent->gameServerInfos.connectionId)) {
        Logger::write("Cannot send AuthentificationTicketMessage.", LOG_ERROR); 
        this->killBot();
        return false;
    }

    return true;
}

bool GameServerConnectionFrame::sendCheckIntegrityMessage() {
    sp<CheckIntegrityMessage> ciMsg = manager->generateCheckIntegrityMessage();

    if(!ciMsg) {
        Logger::write("Cannot generate CheckIntegrityMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }

    if(!sendPacket(ciMsg, dofusBotParent->gameServerInfos.connectionId)) {
        Logger::write("Cannot send CheckIntegrityMessage", LOG_ERROR);
        this->killBot();
        return false;
    }

    return true;
}

void GameServerConnectionFrame::retryAuthentification() {
    if(!parent)
        return;

    sp<Frame> oldAuthFrame = parent->getFrame<AuthentificationFrame>();
    if(oldAuthFrame)
        parent->removeFrame(oldAuthFrame);
    
    parent->addFrame(make_shared<AuthentificationFrame>(manager));
    parent->sendSelfMessage(make_shared<RetryAuthentificationMessage>());
    parent->removeFrame(this);
}