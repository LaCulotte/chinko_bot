#include "AuthentificationFrame.h"

#include "AuthentificationFailureMessage.h"
#include "APIClientDisconnectedMessage.h"

AuthentificationFrame::AuthentificationFrame() : PacketSendingDofusBotFrame() {
    manager = make_shared<AuthentificationManager>();
}

bool AuthentificationFrame::setParent(MessagingUnit *parent){
    if(PacketSendingDofusBotFrame::setParent(parent)) {        
        // Sets the authentification manager if the parent is valid
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

    sp<ProtocolRequired> prMsg;
    sp<HelloConnectMessage> hcMsg;
    sp<IdentificationMessage> idMsg;
    sp<ClientKeyMessage> ckMsg;
    sp<LoginQueueStatusMessage> lqsMsg;
    sp<ServersListMessage> slMsg;
    sp<SelectedServerDataMessage> ssdMsg;

    sp<IdentificationFailedMessage> ifMsg;
    sp<IdentificationFailedForBadVersionMessage> iffbvMsg;

    switch (message->getId()) {
    case BeginAuthentificationMessage::protocolId:
        // Message that requests the beginning of the authentification
        if(currentState == af_idle) {
            baMsg = dynamic_pointer_cast<BeginAuthentificationMessage>(message);

            // Checks if the AuthentificationManager is initialized
            if(!manager){
                // If not, warns the user and builds one
                Logger::write("An authentification was requested but no AuthentificationManager was created. Building one now", LOG_DEBUG);
                manager = make_shared<AuthentificationManager>();
            }

            // Sets credentials
            manager->setCredentials(baMsg->username, baMsg->password);
            if(manager->beginAuthentification(baMsg->serverAdress, baMsg->port, baMsg->autoConnect))
                // If the manager could begin the authentification, changes the frame's state
                currentState = begin_authentification;
            else 
                dofusBotParent->sendMessage(make_shared<AuthentificationFailureMessage>("Missing boUnit links."), dofusBotParent->getAPIUnitId());

        } else {
            Logger::write("Cannot begin authentification : authentification has already begun.", LOG_ERROR);
            dofusBotParent->sendMessage(make_shared<AuthentificationFailureMessage>("Wrong bot status."), dofusBotParent->getAPIUnitId());
        }

        break;

    // TODO : à voir si nécéssaire / si on peut faire mieux
    case RetryAuthentificationMessage::protocolId:
        // Message that requests to retry the authentification
        if(currentState == af_idle) {
            // Checks if the AuthentificationManager has been initialized
            if(!manager) {
                Logger::write("An authentification retry was requested but no AuthentificationManager was specified.", LOG_ERROR);
                this->killBot();
                break;
            }

            if(manager->beginAuthentification()) {
                // If the manager could begin the authentification, changes the frame's state
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
        // Successfully connected to the authentification server
        if(currentState == begin_authentification) {
            csMsg = dynamic_pointer_cast<ConnectionSuccessMessage>(message);
            Logger::write("Connected to the dofus authentification server.", LOG_INFO);

            // Sets authentification server's connection id
            authentificationServerConnectionId = csMsg->connectionId;
            // TODO : enlever qd AuthentificationManager::dofusConnectionId n'est plus utile
            manager->setDofusConnectionId(csMsg->connectionId);

            currentState = rcv_HelloConnectMessage;
            break;
        }

        return false;

    case ConnectionFailureMessage::protocolId:
        // Could not connect to the authentification server
        if(currentState == begin_authentification) {
            cfMsg = dynamic_pointer_cast<ConnectionFailureMessage>(message);
            Logger::write("Could not make the connect to dofus authentification server. Reason : " + cfMsg->reason, LOG_ERROR);

            dofusBotParent->sendMessage(make_shared<AuthentificationFailureMessage>("Could not connect to Dofus' authentification server."), dofusBotParent->getAPIUnitId());

            currentState = af_idle;
            break;
        }

        return false;

    case ProtocolRequired::protocolId:
        // TODO : vérifier si on est au bon state ?
        prMsg = dynamic_pointer_cast<ProtocolRequired>(message);
        // TODO : refuser si mauvaise version
        Logger::write("ProtocolRequired received.", LOG_INFO);
        Logger::write("Required version : " + prMsg->version, LOG_INFO);
        break;

    case HelloConnectMessage::protocolId:
        // First message sent by the authentification server
        if(currentState == rcv_HelloConnectMessage) {
            hcMsg = dynamic_pointer_cast<HelloConnectMessage>(message);
            Logger::write("HelloConnectMessage received.", LOG_INFO);

            // Sends IdentificationMessage and ClientKeyMessage
            if(sendIdentificationMessage(hcMsg) && sendClientKeyMessage()) {
                currentState = snd_IdentificationMessage;
            } else {
                dofusBotParent->sendMessage(make_shared<AuthentificationFailureMessage>("Bot could not send indentification messages"), dofusBotParent->getAPIUnitId());
            }
        } else {
            Logger::write("Received HelloConnectMessage when not supposed to.", LOG_WARNING);
        }

        break;

    case SendPacketSuccessMessage::protocolId:
        // Handles SendPacketSuccessMessage
        if (!handleSendPacketSuccessMessage(dynamic_pointer_cast<SendPacketSuccessMessage>(message)))
            return false;     
        break;

    case SendPacketFailureMessage::protocolId:
        // Handles SendPacketFailureMessage
        if (!handleSendPacketFailureMessage(dynamic_pointer_cast<SendPacketFailureMessage>(message)))
            return false;        
        break;

    // Autre cas ? (Credentials...Message ou équivalent)
    case CredentialsAcknowledgementMessage::protocolId:
        // Credentials are has been received
        if(currentState == rcv_CredentialAknowledgmentMessage) {
            Logger::write("Received CredentialsAcknowledgementMessage.", LOG_INFO);
            currentState = rcv_IdentificationResponseMessage;
        } else { 
            Logger::write("Received CredentialsAcknowledgementMessage when not supposed to.", LOG_WARNING);
        }

        break;

    // Cas IdentificationFailedMessage et autreq
    case IdentificationSuccessMessage::protocolId:
        // Indentification was successful
        if(currentState == rcv_IdentificationResponseMessage) {
            Logger::write("Received IdentificationSucessMessage.", LOG_INFO);
            currentState = end_authentification;
        } else {
            Logger::write("Received IdentificationSucessMessage when not supposed to.", LOG_WARNING);
        }
        
        break;
    
    case IdentificationFailedForBadVersionMessage::protocolId:
        iffbvMsg = dynamic_pointer_cast<IdentificationFailedForBadVersionMessage>(message);
        Logger::write("Required version : " + iffbvMsg->requiredVersion.toString(), LOG_ERROR);
    case IdentificationFailedMessage::protocolId:
        ifMsg = dynamic_pointer_cast<IdentificationFailedMessage>(message);
        Logger::write("Identification failed. Reason id : " + to_string(ifMsg->reason), LOG_ERROR);

        dofusBotParent->sendMessage(make_shared<AuthentificationFailureMessage>("Identification failed. Reason id : " + to_string(ifMsg->reason) + "."), dofusBotParent->getAPIUnitId());
        break;

    // TODO : serverListMessage
    case ServersListMessage::protocolId:
        if(dofusBotParent->getAPIUnitId() == -1) {
            Logger::write("Cannot select server : no APIUnit linked to DofusBotUnit.", LOG_WARNING);
            break;
        }

        slMsg = dynamic_pointer_cast<ServersListMessage>(message);
        dofusBotParent->sendMessage(make_shared<QueryServerSelectionMessage>(slMsg->servers), dofusBotParent->getAPIUnitId());
        break;

    case ServerSelectionMessage::protocolId:
        dofusBotParent->sendPacket(dynamic_pointer_cast<ServerSelectionMessage>(message));
        break;

    // TODO : A mettre dans le GameServerConnectionFrame ? -> Lancer GameServerConnectionFrame à la reception de IdentificationSuccessMessage
    case SelectedServerDataExtendedMessage::protocolId:
    case SelectedServerDataMessage::protocolId:
        // Redirects to the GameServer
        ssdMsg = dynamic_pointer_cast<SelectedServerDataMessage>(message);
        Logger::write("Selected server : " + ssdMsg->address, LOG_INFO);

        // Gets ticket 
        if(!manager->decodeAndSetTicket(string(ssdMsg->ticket.begin(), ssdMsg->ticket.end()))){
            Logger::write("Error on AES decoding.", LOG_ERROR);
            this->killBot();
            break;
        }

        // Removes this frame and replaces it with a GameServerConnectionFrame
        parent->addFrame(make_shared<GameServerConnectionFrame>(manager));
        // Requests the Beginning of the GameServer connection
        parent->sendSelfMessage(make_shared<BeginGameServerConnectionMessage>(ssdMsg));
        parent->removeFrame(this);

        break;

    // TODO in reset : manager->interruptAuthentification
    case APIClientDisconnectedMessage::protocolId:
        Logger::write("temp");
        if(currentState != af_idle) {
            Logger::write("Client disconnected during authentification : bot will be reset.", LOG_WARNING);

            if(manager)
                manager->interruptAuthentification();
            dofusBotParent->resetNextTick();
        }
        break;

    default:
        return false;
    }

    return true;
}

bool AuthentificationFrame::handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) {
    // Checks if the message was sent by this frame
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    // If so, gets the mapped message id
    int messageId = it->second;

    // Logs what message has been sent and changes Frame's state if needed
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
    // Checks if the message was sent by this frame
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    // If so, gets the mapped message id
    int messageId = it->second;

    // Logs what message could not be sent and kills bot if needed
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
    sp<IdentificationMessage> idMsg = manager->generateIdentificationMessage(hcMsg->key.data(), hcMsg->key.size(), hcMsg->salt);
    
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