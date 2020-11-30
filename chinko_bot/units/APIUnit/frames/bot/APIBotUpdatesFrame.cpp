#include "APIBotUpdatesFrame.h"

#define CHARACTER_MESSAGE_UPDATE_MIN 

bool APIBotUpdatesFrame::computeMessage(sp<Message> message, int srcId) {
    for(pair range : updateMessagesIdRanges)
        if(message->getId() >= range.first && message->getId() <= range.second) {
            sp<SendPacketRequestMessage> packetRelay = make_shared<SendPacketRequestMessage>(dynamic_pointer_cast<ConnectionMessage>(message), apiUnitParent->getAPIConnectionId());
            apiUnitParent->sendMessage(packetRelay, apiUnitParent->getConnectionUnitId());
            
            return true;
        }

    return false;
}