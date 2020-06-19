#include "GameServerConnectionFrame.h"

bool GameServerConnectionFrame::setParent(MessagingUnit* parent) {
    if(dynamic_cast<DofusBotUnit *>(parent)){
        this->parent = parent;
        return true;
    }

    return false;
}

// TODO : reset propre en cas d'erreur : message?
bool GameServerConnectionFrame::computeMessage(sp<Message> message, int srcId) {
    DofusBotUnit* botParent = dynamic_cast<DofusBotUnit *>(parent);

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
                // TODO : reset complet (Erreur de progammation, pas de connection/authentification)
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
                // TODO : reset vers authentification
            }
        } else {
            Logger::write("Tried to begin the GameServer connection while it is already started.", LOG_WARNING);
        }

        break;
    
    case ConnectionSuccessMessage::protocolId:
        csMsg = dynamic_pointer_cast<ConnectionSuccessMessage>(message);
        manager->setDofusConnectionId(csMsg->connectionId);

        botParent->gameServerInfos.connectionId = csMsg->connectionId;
        botParent->gameServerInfos.adress = serverAddress;
        
        currentState = rcv_HelloGameMessage;
        Logger::write("Connected to the game server : " + serverAddress, LOG_INFO);
        break;

    case ConnectionFailureMessage::protocolId:
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
        Logger::write("ProtocolRequiredMessage received", LOG_INFO);
        Logger::write("Required version : " + to_string(prMsg->requiredVersion) + "; Current version : " + to_string(prMsg->currentVersion), LOG_INFO);
        break;

    case HelloGameMessage::protocolId:
        if(currentState == rcv_HelloGameMessage) {
            Logger::write("Received HelloGameMessage", LOG_INFO);

            if(manager->sendAuthentificationTicketMessage()) {
                currentState = snd_AuthentificationTicketMessage;
            } else {
                // TODO : reset
            }

        } else {
            Logger::write("Received HelloGameMessage when not supposed to.", LOG_WARNING);
        }

        break;

    case RawDataMessage::protocolId:
        if(currentState == rcv_RawDataMessage) {
            Logger::write("Received RawDataMessage", LOG_INFO);

            if(manager->sendCheckIntegrityMessage()) {
                currentState = snd_CheckIntegrityMessage;
            } else {
                // TODO : reset
            }
        } else {
            Logger::write("Received RawDataMessage when not supposed to.", LOG_WARNING);
        }
        break;

    // TODO : cas AuthentificationTicketRefusedMessage
    case AuthentificationTicketAcceptedMessage::protocolId:
        if(currentState == rcv_AuthentificationTicketResponseMessage) {
            sp<CharacterSelectionFrame> csFrame(new CharacterSelectionFrame());
            if(parent->addFrame(csFrame)) {
                parent->sendSelfMessage(make_shared<BeginCharacterSelectionMessage>());
                parent->removeFrame(this);
            } else {
                Logger::write("Could not add CharacterSelectionFrame to parent.", LOG_ERROR);
                //TODO : reset
            }
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
    switch (currentState) {
    case snd_AuthentificationTicketMessage:
        Logger::write("AuthentificationTicketMessage sent.", LOG_INFO);
        currentState = rcv_RawDataMessage;
        break;
    case snd_CheckIntegrityMessage:
        Logger::write("CheckIntegrityMessage sent.", LOG_INFO);
        currentState = rcv_AuthentificationTicketResponseMessage;
        break;
    default:
        return false;
    }

    return true;
}

bool GameServerConnectionFrame::handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) {
    switch (currentState) {
    case snd_AuthentificationTicketMessage:
        Logger::write("AuthentificationTicketMessage could not be sent. Reason : " + message->reason, LOG_INFO);
        // TODO : Reset ou retry
        break;
    case snd_CheckIntegrityMessage:
        Logger::write("CheckIntegrityMessage could not be sent. Reason : " + message->reason, LOG_INFO);
        // TODO : Reset ou retry
        break;
    default:
        return false;
    }

    return true;
}