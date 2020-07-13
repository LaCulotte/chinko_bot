#include "AuthentificationFrame.h"

AuthentificationFrame::AuthentificationFrame() : PacketSendingDofusBotFrame() {
    manager = make_shared<AuthentificationManager>();
}

bool AuthentificationFrame::setParent(MessagingUnit *parent){
    if(PacketSendingDofusBotFrame::setParent(parent)) {        
        if(!manager)
            manager = make_shared<AuthentificationManager>();
        
        manager->setBot(dynamic_cast<DofusBotUnit*>(parent));

        return true;
    }

    return false;
}

// TODO : gérer le cas autoConnect = false (ds IdentificationMessage)
bool AuthentificationFrame::computeMessage(sp<Message> message, int srcId) {

    sp<BeginAuthentificationMessage> baMsg;
    sp<ConnectionSuccessMessage> csMsg;
    sp<ConnectionFailureMessage> cfMsg;
    sp<SendPacketFailureMessage> spfMsg;

    sp<ProtocolRequiredMessage> prMsg;
    sp<HelloConnectMessage> hcMsg;
    sp<IdentificationMessage> idMsg;
    sp<ClientKeyMessage> ckMsg;
    sp<LoginQueueStatusMessage> lqsMsg;
    sp<SelectedServerDataExtendedMessage> ssdeMsg;

    switch (message->getId()) {
    case BeginAuthentificationMessage::protocolId:
        if(currentState == af_idle) {
            baMsg = dynamic_pointer_cast<BeginAuthentificationMessage>(message);

            if(!manager){
                Logger::write("An authentification was requested but no AuthentificationManager was created. Building one now", LOG_DEBUG);
                manager = make_shared<AuthentificationManager>();
            }

            manager->setCredentials(baMsg->username, baMsg->password);
            if(manager->beginAuthentification(baMsg->serverAdress, baMsg->port))
                currentState = begin_authentification;

        } else {
            Logger::write("Cannot begin authentification : authentification has already begun.", LOG_ERROR);
        }

        break;

    case RetryAuthentificationMessage::protocolId:
        if(currentState == af_idle) {
            if(!manager) {
                Logger::write("An authentification retry was requested but no AuthentificationManager was specified.", LOG_ERROR);
                this->killBot();
            }

            if(manager->beginAuthentification()) {
                currentState = begin_authentification;
            } else {
                Logger::write("Authentification retry has failed.", LOG_ERROR);
                this->killBot();
            }

        } else {
            Logger::write("Cannot retry authentification : authentification has already begun.", LOG_ERROR);
        }
        break;

    case ConnectionSuccessMessage::protocolId:
        if(currentState = begin_authentification) {
            csMsg = dynamic_pointer_cast<ConnectionSuccessMessage>(message);
            Logger::write("Connected to the dofus authentification server.", LOG_INFO);

            authentificationServerConnectionId = csMsg->connectionId;
            // TODO : enlever qd AuthentificationManager::dofusConnectionId n'est plus utile
            manager->setDofusConnectionId(csMsg->connectionId);

            currentState = rcv_HelloConnectMessage;
            break;
        }

        return false;

    case ConnectionFailureMessage::protocolId:
        if(currentState == begin_authentification) {
            cfMsg = dynamic_pointer_cast<ConnectionFailureMessage>(message);
            Logger::write("Could not make the connect to dofus authentification server. Reason : " + cfMsg->reason, LOG_ERROR);

            currentState = af_idle;
            break;
        }

        return false;

    case ProtocolRequiredMessage::protocolId:
        // TODO : vérifier si on est au bon state ?
        prMsg = dynamic_pointer_cast<ProtocolRequiredMessage>(message);
        // TODO : refuser si mauvaise version
        Logger::write("ProtocolRequiredMessage received.", LOG_INFO);
        Logger::write("Required version : " + to_string(prMsg->requiredVersion) + "; Current version : " + to_string(prMsg->currentVersion), LOG_INFO);
        break;

    case HelloConnectMessage::protocolId:
        if(currentState == rcv_HelloConnectMessage) {
            hcMsg = dynamic_pointer_cast<HelloConnectMessage>(message);
            Logger::write("HelloConnectMessage received.", LOG_INFO);

            if(sendIdentificationMessage(hcMsg)) {
                currentState = snd_IdentificationMessage;

                sendClientKeyMessage();
            }
        } else {
            Logger::write("Received HelloConnectMessage when not supposed to.", LOG_WARNING);
        }

        break;

    case SendPacketSuccessMessage::protocolId:
        if (!handleSendPacketSuccessMessage(dynamic_pointer_cast<SendPacketSuccessMessage>(message)))
            return false;     
        break;

    case SendPacketFailureMessage::protocolId:
        if (!handleSendPacketFailureMessage(dynamic_pointer_cast<SendPacketFailureMessage>(message)))
            return false;        
        break;

    case CredentialsAcknowledgementMessage::protocolId:
        if(currentState == rcv_CredentialAknowledgmentMessage) {
            Logger::write("Received CredentialsAcknowledgementMessage.", LOG_INFO);
            currentState = rcv_IdentificationResponseMessage;
        } else { 
            Logger::write("Received CredentialsAcknowledgementMessage when not supposed to.", LOG_WARNING);
        }

        break;

    case IdentificationSuccessMessage::protocolId:
        if(currentState == rcv_IdentificationResponseMessage) {
            Logger::write("Received IdentificationSucessMessage.", LOG_INFO);
            currentState = end_authentification;
        } else {
            Logger::write("Received IdentificationSucessMessage when not supposed to.", LOG_WARNING);
        }
        
        break;

    // A mettre dans le GameServerConnectionFrame ? -> Lancer GameServerConnectionFrame à la reception de IdentificationSuccessMessage
    case SelectedServerDataExtendedMessage::protocolId:
        ssdeMsg = dynamic_pointer_cast<SelectedServerDataExtendedMessage>(message);
        Logger::write("Selected server : " + ssdeMsg->address, LOG_INFO);
        if(!manager->decodeAndSetTicket(ssdeMsg->ticket)){
            Logger::write("Error on AES decoding.", LOG_ERROR);
            this->killBot();
            break;
        }

        parent->addFrame(make_shared<GameServerConnectionFrame>(manager));
        parent->sendSelfMessage(make_shared<BeginGameServerConnectionMessage>(ssdeMsg));
        parent->removeFrame(this);

        break;

    default:
        return false;
    }

    return true;
}

bool AuthentificationFrame::handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) {
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    int messageId = it->second;

    switch (messageId)
    {
    case IdentificationMessage::protocolId:
        if(currentState == snd_IdentificationMessage) {
            Logger::write("IdentificationMessage sent.", LOG_INFO);
            currentState = rcv_CredentialAknowledgmentMessage;
        } else {
            Logger::write("IdentificationMessage was sent but was not supposed to.", LOG_WARNING);
        }
        break;

    case ClientKeyMessage::protocolId:
        Logger::write("ClientKeyMessage sent.", LOG_INFO);
        break;
    
    default:
        Logger::write("Message of id " + to_string(messageId) + " sent.", LOG_INFO);
        break;
    }

    packetId_to_messageId.erase(it);

    return true;
}

bool AuthentificationFrame::handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) {
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    int messageId = it->second;

    switch (messageId)
    {
    case IdentificationMessage::protocolId:
        if(currentState == snd_IdentificationMessage) {
            Logger::write("IdentificationMessage could not be sent : " + message->reason + ".", LOG_WARNING);
            this->killBot();
        } else {
            Logger::write("IdentificationMessage could not be sent but was not supposed to.", LOG_WARNING);
        }
        break;

    case ClientKeyMessage::protocolId:
        Logger::write("ClientKeyMessage could not be sent.", LOG_WARNING);
        this->killBot();
        break;
    
    default:
        Logger::write("Message of id " + to_string(messageId) + " could not be sent.", LOG_WARNING);
        // A voir si bot kill
        break;
    }

    packetId_to_messageId.erase(it);

    return true;
}

bool AuthentificationFrame::sendIdentificationMessage(sp<HelloConnectMessage> hcMsg) {
    sp<IdentificationMessage> idMsg = manager->generateIdentificationMessage(hcMsg->key, hcMsg->keyLength, hcMsg->salt);
    
    if(!idMsg) {
        Logger::write("Cannot build IdentificationMessage.", LOG_ERROR);
        this->killBot();        
        return false;
    }

    if(!sendPacket(idMsg, authentificationServerConnectionId)) {
        Logger::write("Cannot send IdentificationMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }

    return true;
}

bool AuthentificationFrame::sendClientKeyMessage() {
    sp<ClientKeyMessage> ckMsg = manager->generateClientKeyMessage();

    if(!ckMsg) {
        Logger::write("Cannot send ClientKeyMessage. Disconnection.", LOG_ERROR);
        this->killBot();
        return false;
    }

    if(!sendPacket(ckMsg, authentificationServerConnectionId)) {
        Logger::write("Cannot send ClientKeyMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }


    return true;
}