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

bool AuthentificationFrame::computeMessage(sp<Message> message, int srcId) {

    DofusBotUnit* botParent = dynamic_cast<DofusBotUnit *>(parent);

    sp<UnknownDofusMessage> udMsg;
    sp<BeginAuthentificationMessage> baMsg;
    sp<ConnectionSuccessMessage> csMsg;
    sp<ConnectionFailureMessage> cfMsg;

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
        Logger::write("Connected to the dofus authentification server.", LOG_DEBUG);

        manager->setDofusConnectionId(csMsg->connectionId);
        break;

    case ConnectionFailureMessage::protocolId:
        cfMsg = dynamic_pointer_cast<ConnectionFailureMessage>(message);
        Logger::write("Could not make the connect to dofus authentification server. Reason : " + cfMsg->reason, LOG_ERROR);
        break;

    case UnknownDofusMessage::protocolId:
        udMsg = dynamic_pointer_cast<UnknownDofusMessage>(message);
        Logger::write("Got message of unkown id : " + to_string(udMsg->real_id) + ";", LOG_DEBUG);
        Logger::write("Length: " + to_string(udMsg->getLength()) + ";", LOG_DEBUG);
        Logger::write("Data : " + udMsg->data->toString() + ";", LOG_DEBUG);
        break;

    default:
        return false;
    }

    return true;
}