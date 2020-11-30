#include "APIClientConnectionFrame.h"

#include "APIClientDisconnectedMessage.h"
#include "DisconnectedMessage.h"

#include "BotConnectionStatusRequestMessage.h"
#include "BotConnectionStatusMessage.h"
#include "APIAuthentificationStatusMessage.h"

#include "BotCharacterInformationsRequestMessage.h"

#include "APIBotConnectionFrame.h"
#include "APIBotUpdatesFrame.h"

bool APIClientConnectionFrame::computeMessage(sp<Message> message, int srcId) {
    sp<ConnectionIdMessage> ciMsg;
    sp<DisconnectedMessage> dMsg;

    sp<BotConnectionStatusMessage> bcMsg;

    switch (message->getId())
    {
    case ConnectionIdMessage::protocolId:
        ciMsg = dynamic_pointer_cast<ConnectionIdMessage>(message);
        if(ciMsg->ids.size() > 0)
            if(apiUnitParent->setAPIConnectionId(ciMsg->ids[0]))
                apiUnitParent->sendMessage(make_shared<BotConnectionStatusRequestMessage>(), apiUnitParent->getDofusBotUnitId());
        break;

    case BotConnectionStatusMessage::protocolId:
        bcMsg = dynamic_pointer_cast<BotConnectionStatusMessage>(message);
        apiUnitParent->sendMessage(make_shared<SendPacketRequestMessage>(make_shared<APIAuthentificationStatusMessage>(bcMsg->connected), apiUnitParent->getAPIConnectionId()), apiUnitParent->getConnectionUnitId());
        if(bcMsg->connected) {
            parent->addFrame(make_shared<APIBotUpdatesFrame>());
            parent->sendMessage(make_shared<BotCharacterInformationsRequestMessage>(), apiUnitParent->getDofusBotUnitId());
        } else {
            parent->addFrame(make_shared<APIBotConnectionFrame>());
        }

        break;
    
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