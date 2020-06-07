#include "PingFrame.h"

bool PingFrame::computeMessage(sp<Message> message, int srcId){
    if(!parent)
        return false;

    // If the recevied message is a PingMessage, sends a PongMessage to the sender
    if(message->getId() == PingMessage::protocolId){
        parent->sendMessage(make_shared<PongMessage>(), srcId);
        return true;
    }

    return false;
}