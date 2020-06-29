#include "BasicDofusBotFrame.h"

bool BasicDofusBotFrame::setParent(MessagingUnit* parent) {
    this->dofusBotParent = dynamic_cast<DofusBotUnit *>(parent); 
    if(dofusBotParent){
        this->parent = parent;
        return true;
    }

    return false;
}

bool BasicDofusBotFrame::computeMessage(sp<Message> message, int srcId) {
    sp<SendPacketFailureMessage> spfMsg;
    
    sp<UnknownDofusMessage> udMsg;
    sp<SequenceNumberMessage> snMsg;

    switch (message->getId()) {
    case UnknownDofusMessage::protocolId:
        udMsg = dynamic_pointer_cast<UnknownDofusMessage>(message);
        Logger::write("Got message of unknown id : " + to_string(udMsg->real_id) + "; Length : " + to_string(udMsg->getLength()) + ";", LOG_DEBUG);
        // if(udMsg->data)
        //     Logger::write("Data : " + udMsg->data->toString(), LOG_DEBUG);
        break;
    
    case SequenceNumberRequestMessage::protocolId:
        snMsg = make_shared<SequenceNumberMessage>(++sequenceNumber);
        Logger::write("Received SequenceNumberRequestMessage", LOG_INFO);
        parent->sendMessage(make_shared<SendPacketRequestMessage>(snMsg, dofusBotParent->gameServerInfos.connectionId), dofusBotParent->connectionUnitId);
        currentState = snd_SequenceNumberMessage;
        break;

    case SendPacketSuccessMessage::protocolId:
        if(handleSendPacketSuccessMessage(dynamic_pointer_cast<SendPacketSuccessMessage>(message)))
            break;

        return false;

    case SendPacketFailureMessage::protocolId:
        if(handleSendPacketFailureMessage(dynamic_pointer_cast<SendPacketFailureMessage>(message)))
            break;

        return false;

    default:
        return false;
    }

    return true;
}

bool BasicDofusBotFrame::handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) {
    switch(currentState) {
    case snd_SequenceNumberMessage:
        Logger::write("SequenceNumberMessage sent", LOG_INFO);
        currentState = bdb_idle;
        break;
    default:
        return false;
    }

    return true;
}

bool BasicDofusBotFrame::handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) {
    switch(currentState) {
    case snd_SequenceNumberMessage:
        Logger::write("Cannot send SequenceNumberMessag. Reason : " + message->reason, LOG_INFO);
        // TODO : reset
        break;
    default:
        return false;
    }

    return true;
}