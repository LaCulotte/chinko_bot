#include "BasicDofusBotFrame.h"

bool BasicDofusBotFrame::computeMessage(sp<Message> message, int srcId) {
    sp<UnknownDofusMessage> udMsg;

    switch (message->getId()) {
    case UnknownDofusMessage::protocolId:
        udMsg = dynamic_pointer_cast<UnknownDofusMessage>(message);
        Logger::write("Got message of unknown id : " + to_string(udMsg->real_id) + "; Length : " + to_string(udMsg->getLength()) + ";", LOG_DEBUG);
        // if(udMsg->data)
        //     Logger::write("Data : " + udMsg->data->toString(), LOG_DEBUG);
        break;
        
    default:
        return false;
    }

    return true;
}