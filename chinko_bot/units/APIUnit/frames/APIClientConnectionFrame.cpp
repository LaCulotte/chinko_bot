#include "APIClientConnectionFrame.h"

#include "APIClientDisconnectedMessage.h"
#include "DisconnectedMessage.h"

bool APIClientConnectionFrame::computeMessage(sp<Message> message, int srcId) {
    sp<DisconnectedMessage> dMsg;

    switch (message->getId())
    {
    case DisconnectedMessage::protocolId:
        dMsg = dynamic_pointer_cast<DisconnectedMessage>(message);
        for(int id : dMsg->connectionIds) {
            if(id == apiUnitParent->getAPIConnectionId()) {
                apiUnitParent->resetAPIConnectionId();
                Logger::write("API client disconnected", LOG_DEBUG);

                apiUnitParent->sendMessage(make_shared<APIClientDisconnectedMessage>(), apiUnitParent->getDofusBotUnitId());
                return true;
            }
        }
        return false;
    
    default:
        return false;
    }

    return true;
}