#include "GameServerConnectionFrame.h"

bool GameServerConnectionFrame::computeMessage(sp<Message> message, int srcId) {
    sp<BeginGameServerConnectionMessage> bgscMsg;
    sp<ConnectionSuccessMessage> csMsg;
    sp<ConnectionFailureMessage> cfMsg;
    sp<BasicCharactersListMessage> bclMsg;

    sp<UnknownDofusMessage> udMsg;
    sp<ProtocolRequired> prMsg;

    switch (message->getId())
    {
    case BeginGameServerConnectionMessage::protocolId:
        // Message that request for the beginning of the Game server connection
        if(currentState == gcsf_idle) {
            bgscMsg = dynamic_pointer_cast<BeginGameServerConnectionMessage>(message);

            // Checks if the manager has been initialized
            if(!manager) {
                Logger::write("Cannot begin Game server connection if there is no AuthentificationManager.", LOG_ERROR);
                this->killBot();
                break;
            }

            // Saves Game server informations
            serverAddress = bgscMsg->ssdMsg->address;
            serverPorts = bgscMsg->ssdMsg->ports;
            if(serverPorts.size() <= 0) {
                Logger::write("Cannot connect to the game server (" + serverAddress + ") : No port specified.", LOG_ERROR);
                // TODO : reset vers authentification
                break;
            }
            serverPorts_i = 0;
            
            // Tries to connect to the Game server
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
        // Game server connection was successful
        if(currentState == begin_GameServerConnection) {
            csMsg = dynamic_pointer_cast<ConnectionSuccessMessage>(message);

            // Saves the game server infos
            dofusBotParent->gameServerInfos.connectionId = csMsg->connectionId;
            dofusBotParent->gameServerInfos.adress = serverAddress;
            
            currentState = rcv_HelloGameMessage;
            Logger::write("Connected to the game server : " + serverAddress, LOG_INFO);
            break;
        }

        return false;

    case ConnectionFailureMessage::protocolId:
        // Game server connection was unsuccessful
        if(currentState == begin_GameServerConnection) {
            cfMsg = dynamic_pointer_cast<ConnectionFailureMessage>(message);

            Logger::write("Failed to connect to " + serverAddress + ":" + to_string(serverPorts[serverPorts_i]) + "; Reason : " + cfMsg->reason, LOG_WARNING);
            // Tries to connect to next port
            if(++serverPorts_i >= serverPorts.size()) {
                Logger::write("Cannot connect to the game server", LOG_ERROR);
                // TODO : reset authentification
                break;
            } else {
                // If there is no valid port, resets and returns to authentification
                Logger::write("Trying an next port", LOG_WARNING);
                if(!manager->connectGameServer(serverAddress, serverPorts[serverPorts_i])) {
                    // TODO : reset vers authentification
                }
            }
            break;
        }

        return false;

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

    case ProtocolRequired::protocolId:
        prMsg = dynamic_pointer_cast<ProtocolRequired>(message);
        // TODO : refuser si mauvaise version
        Logger::write("ProtocolRequired received", LOG_INFO);
        Logger::write("Required version : " + prMsg->version, LOG_INFO);
        break;

    case HelloGameMessage::protocolId:
        // First message from the game server
        if(currentState == rcv_HelloGameMessage) {
            Logger::write("Received HelloGameMessage", LOG_INFO);

            // Tries to send AuthenticationTicketMessage
            if (sendAuthenticationTicketMessage())
                currentState = snd_AuthenticationTicketMessage;

        } else {
            Logger::write("Received HelloGameMessage when not supposed to.", LOG_WARNING);
        }

        break;

    case RawDataMessage::protocolId:
        // Fake antibot message
        if(currentState == rcv_RawDataMessage) {
            Logger::write("Received RawDataMessage", LOG_INFO);

            // Sends random CheckIntegrityMessage
            if(sendCheckIntegrityMessage())
                currentState = snd_CheckIntegrityMessage;

        } else {
            Logger::write("Received RawDataMessage when not supposed to.", LOG_WARNING);
        }
        break;

    // TODO : cas AuthenticationTicketRefusedMessage
    case AuthenticationTicketAcceptedMessage::protocolId:
        // Authentification to the Game server was successful
        if(currentState == rcv_AuthenticationTicketResponseMessage) {
            Logger::write("Received AuthenticationTicketAcceptedMessage", LOG_INFO);

            // Removes this frame and replaces it with a Character selection frame
            sp<CharacterSelectionFrame> csFrame(new CharacterSelectionFrame());
            if(parent->addFrame(csFrame)) {
                // Requests the beginning of the character selection
                parent->sendSelfMessage(make_shared<BeginCharacterSelectionMessage>());
                parent->removeFrame(this);
            } else {
                Logger::write("Could not add CharacterSelectionFrame to parent.", LOG_ERROR);
                this->killBot();
                break;
            }
            currentState = end_GameServerConnection;
        } else {
            Logger::write("Received AuthenticationTicketAcceptedMessage when not supposed to.", LOG_WARNING);
        }

        break;

    default:
        return false;
    }

    return true;
}

bool GameServerConnectionFrame::handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) {
    // Checks if the message was sent by this frame
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    // If so, gets the mapped message id
    int messageId = it->second;

    // Logs what message has been sent and changes Frame's state if needed
    switch (messageId)
    {
    case AuthenticationTicketMessage::protocolId:
        if(currentState == snd_AuthenticationTicketMessage) {
            Logger::write("AuthenticationTicketMessage sent.", LOG_INFO);
            currentState = rcv_RawDataMessage;
        } else {
            Logger::write("AuthenticationTicketMessage sent but was not supposed to.", LOG_WARNING);
        } 
        break;
    
    case CheckIntegrityMessage::protocolId:
        if(currentState == snd_CheckIntegrityMessage) {
            Logger::write("CheckIntegrityMessage sent.", LOG_INFO);
            currentState = rcv_AuthenticationTicketResponseMessage;
        } else {
            Logger::write("AuthenticationTicketMessage sent but was not supposed to.", LOG_WARNING);
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
    // Checks if the message was sent by this frame
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    // If so, gets the mapped message id
    int messageId = it->second;

    // Logs what message could not be sent and kills bot if needed
    switch (messageId)
    {
    case AuthenticationTicketMessage::protocolId:
        if(currentState == snd_AuthenticationTicketMessage) {
            Logger::write("AuthenticationTicketMessage could not be sent. Reason : " + message->reason, LOG_WARNING);
            this->killBot();
        } else {
            Logger::write("AuthenticationTicketMessage could not be but was not supposed to. Reason : " + message->reason, LOG_WARNING);
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

bool GameServerConnectionFrame::sendAuthenticationTicketMessage() {
    sp<AuthenticationTicketMessage> atMsg = manager->generateAuthenticationTicketMessage();
    if(!atMsg) {
        Logger::write("Cannot generate AuthenticationTicketMessage", LOG_ERROR);
        this->killBot();
        return false;
    }
    if(!sendPacket(atMsg, dofusBotParent->gameServerInfos.connectionId)) {
        Logger::write("Cannot send AuthenticationTicketMessage.", LOG_ERROR); 
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

// Rename
void GameServerConnectionFrame::retryAuthentification() {
    // Checks if there is a parent
    if(!parent)
        return;

    // Removes eventual AuthentificationFrame leftovers
    // TODO : getAllFrames
    sp<Frame> oldAuthFrame = parent->getFrame<AuthentificationFrame>();
    if(oldAuthFrame)
        parent->removeFrame(oldAuthFrame);
    
    // Removes this frame and replaces it with a new AuthentificationFrame
    parent->addFrame(make_shared<AuthentificationFrame>(manager));
    // Requests the beginning of an authentification
    parent->sendSelfMessage(make_shared<RetryAuthentificationMessage>());
    parent->removeFrame(this);
}