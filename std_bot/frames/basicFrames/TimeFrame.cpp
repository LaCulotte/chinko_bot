#include "TimeFrame.h"

bool TimeFrame::computeMessage(sp<Message> message, int srcId) {
    sp<TimedMessage> tMsg;

    switch (message->getId())
    {
    case TimedMessage::protocolId:
        tMsg = dynamic_pointer_cast<TimedMessage>(message);

        if((chrono::steady_clock::now() - tMsg->beginTime) > tMsg->waitTime) {
            parent->sendSelfMessage(tMsg->message);
        } else {
            tMsg->lifetime ++;
            return false;
        }   
        break;
    
    default:
        return false;
    }

    return true;
}