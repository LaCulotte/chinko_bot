#include "AuthentificationFrame.h"

bool AuthentificationFrame::setParent(MessagingUnit *parent){
    if(dynamic_cast<DofusBotUnit*>(parent))
        return Frame::setParent(parent);

    return false;
}

bool AuthentificationFrame::computeMessage(sp<Message> message, int srcId) {

    DofusBotUnit* botParent = dynamic_cast<DofusBotUnit *>(parent);

    sp<UnknownDofusMessage> udMsg;
    sp<BeginAuthentificationMessage> baMsg;

    switch (message->getId()) {
    case BeginAuthentificationMessage::protocolId:
        baMsg = dynamic_pointer_cast<BeginAuthentificationMessage>(message);

        if(true){
            sp<DofusClientConnection> conn (new DofusClientConnection());
            sp<ConnectionRequestMessage> crMsg(new ConnectionRequestMessage(conn, baMsg->serverAdress, baMsg->port));

            if(botParent->connectionUnitId == -1){
                botParent->connectionUnitId = parent->getMessageInterfaceOutId<ConnectionUnit>();
                if(botParent->connectionUnitId == -1){
                    Logger::write("A ConnectionUnit must be linked in order to begin connections.", LOG_ERROR);
                    break;
                }
            }

            parent->sendMessage(crMsg, botParent->connectionUnitId);
        }

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