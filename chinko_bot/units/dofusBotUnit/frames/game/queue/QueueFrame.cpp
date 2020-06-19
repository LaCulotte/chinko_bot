#include "QueueFrame.h"

bool QueueFrame::computeMessage(sp<Message> message, int srcId) {

    sp<LoginQueueStatusMessage> lqsMsg;
    sp<QueueStatusMessage> qsMsg;

    switch (message->getId()) {
    case QueueStatusMessage::protocolId:
        qsMsg = dynamic_pointer_cast<QueueStatusMessage>(message);
        Logger::write("Queue position : " + to_string(qsMsg->position) + "/" + to_string(qsMsg->total), LOG_INFO);
        break;
    
    case LoginQueueStatusMessage::protocolId:
        lqsMsg = dynamic_pointer_cast<LoginQueueStatusMessage>(message);
        Logger::write("Login queue position : " + to_string(lqsMsg->position) + "/" + to_string(lqsMsg->total), LOG_INFO);
        break;
    
    default:
        return false;
    }

    return true;
}