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
            // Sets the APIUnit's APIConnection's id if it is waiting for it 
            if(apiUnitParent->setAPIConnectionId(ciMsg->ids[0]))
                // Checks if the bot is already connected to a game server
                apiUnitParent->sendMessage(make_shared<BotConnectionStatusRequestMessage>(), apiUnitParent->getDofusBotUnitId());
        break;

    case BotConnectionStatusMessage::protocolId:
        bcMsg = dynamic_pointer_cast<BotConnectionStatusMessage>(message);
        // Sends bot's connection status to the API client
        apiUnitParent->sendMessage(make_shared<SendPacketRequestMessage>(make_shared<APIAuthentificationStatusMessage>(bcMsg->connected), apiUnitParent->getAPIConnectionId()), apiUnitParent->getConnectionUnitId());
        if(bcMsg->connected) {
            // If the bot is connected, asks for the bot's updates & informations
            parent->addFrame(make_shared<APIBotUpdatesFrame>());
            parent->sendMessage(make_shared<BotCharacterInformationsRequestMessage>(), apiUnitParent->getDofusBotUnitId());
        } else {
            // Else, adds a frame for connecting the bot to the server
            parent->addFrame(make_shared<APIBotConnectionFrame>());
        }

        break;
    
    case DisconnectedMessage::protocolId:
        dMsg = dynamic_pointer_cast<DisconnectedMessage>(message);
        for(int id : dMsg->connectionIds) {
            if(id == apiUnitParent->getAPIConnectionId()) {
                // If the client has disconnected, reset the APIUnit
                apiUnitParent->resetAPIConnectionId();
                Logger::write("API client disconnected", LOG_DEBUG);

                // Notifies the BotUnit
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