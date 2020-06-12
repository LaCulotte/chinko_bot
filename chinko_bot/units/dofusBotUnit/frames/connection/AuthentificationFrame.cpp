#include "AuthentificationFrame.h"

AuthentificationFrame::AuthentificationFrame(){
    manager = make_shared<AuthentificationManager>();
}

bool AuthentificationFrame::setParent(MessagingUnit *parent){
    if(dynamic_cast<DofusBotUnit*>(parent)) {

        if(Frame::setParent(parent)){
        
            if(!manager)
                manager = make_shared<AuthentificationManager>();
            
            manager->setBot(dynamic_cast<DofusBotUnit*>(parent));

            return true;
        }
    }

    return false;
}

// TODO : gérer le cas autoConnect = false (ds IdentificationMessage)
// TODO : reset propre en cas d'erreur
bool AuthentificationFrame::computeMessage(sp<Message> message, int srcId) {

    DofusBotUnit* botParent = dynamic_cast<DofusBotUnit *>(parent);

    sp<UnknownDofusMessage> udMsg;
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
        baMsg = dynamic_pointer_cast<BeginAuthentificationMessage>(message);

        if(!manager){
            Logger::write("An authentification was requested but no AuthentificationManager was created. Building one now", LOG_DEBUG);
            manager = make_shared<AuthentificationManager>();
        }

        manager->setCredentials(baMsg->username, baMsg->password);
        manager->beginAuthentification(baMsg->serverAdress, baMsg->port);

        break;

    case ConnectionSuccessMessage::protocolId:
        csMsg = dynamic_pointer_cast<ConnectionSuccessMessage>(message);
        Logger::write("Connected to the dofus authentification server.", LOG_INFO);

        manager->setDofusConnectionId(csMsg->connectionId);
        break;

    case ConnectionFailureMessage::protocolId:
        cfMsg = dynamic_pointer_cast<    ConnectionFailureMessage>(message);
        Logger::write("Could not make the connect to dofus authentification server. Reason : " + cfMsg->reason, LOG_ERROR);
        break;

    case ProtocolRequiredMessage::protocolId:
        prMsg = dynamic_pointer_cast<ProtocolRequiredMessage>(message);
        Logger::write("ProtocolRequiredMessage received", LOG_INFO);
        Logger::write("Required version : " + to_string(prMsg->requiredVersion) + "; Current version : " + to_string(prMsg->currentVersion), LOG_INFO);
        break;

    case HelloConnectMessage::protocolId:
        hcMsg = dynamic_pointer_cast<HelloConnectMessage>(message);
        Logger::write("HelloConnectMessage received", LOG_INFO);
        if(!manager->sendIdentificationMessage(hcMsg->key, hcMsg->keyLength, hcMsg->salt)) {
            Logger::write("Cannot send IdentificationMessage. Disconnection.", LOG_ERROR);
            manager->interruptAuthentification();
        }
        if(!manager->sendClientKeyMessage()) {
            Logger::write("Cannot send ClientKeyMessage. Disconnection.", LOG_ERROR);
            manager->interruptAuthentification();
        }
        break;
    
    case SendPacketFailureMessage::protocolId:
        spfMsg = dynamic_pointer_cast<SendPacketFailureMessage>(message);
        Logger::write("Failed to send IdentificationMessage or ClientKeyMessage. Reason : " + spfMsg->reason, LOG_ERROR);
        break;

    case CredentialsAcknowledgementMessage::protocolId:
        Logger::write("Received CredentialsAcknowledgementMessage", LOG_INFO);
        break;

    case LoginQueueStatusMessage::protocolId:
        lqsMsg = dynamic_pointer_cast<LoginQueueStatusMessage>(message);
        Logger::write("Queue position : " + to_string(lqsMsg->position) + "/" + to_string(lqsMsg->total), LOG_INFO);
        break;

    case IdentificationSuccessMessage::protocolId:
        Logger::write("Received IdentificationSucessMessage", LOG_INFO);
        break;

    case SelectedServerDataExtendedMessage::protocolId:
        ssdeMsg = dynamic_pointer_cast<SelectedServerDataExtendedMessage>(message);
        Logger::write("Selected server : " + ssdeMsg->address, LOG_INFO);
        // manager->connectGameServer(ssdeMsg->address, ssdeMsg->ports[0], ssdeMsg->ticket);
        if(!manager->decodeAndSetTicket(ssdeMsg->ticket)){
            Logger::write("Error on AES decoding.", LOG_ERROR);
            // TODO : reset total
            break;
        }
        parent->addFrame(make_shared<GameServerConnectionFrame>(manager));
        parent->sendSelfMessage(make_shared<BeginGameServerConnectionMessage>(ssdeMsg));
        parent->removeFrame(this);
        break;

    // TODO : enlever
    case UnknownDofusMessage::protocolId:
        udMsg = dynamic_pointer_cast<UnknownDofusMessage>(message);
        Logger::write("Got message  of unkown id : " + to_string(udMsg->real_id) + ";", LOG_DEBUG);
        Logger::write("Length: " + to_string(udMsg->getLength()) + ";", LOG_DEBUG);
        if(udMsg->data)
            Logger::write("Data : " + udMsg->data->toString(), LOG_DEBUG);
        break;

    default:
        return false;
    }

    return true;
}