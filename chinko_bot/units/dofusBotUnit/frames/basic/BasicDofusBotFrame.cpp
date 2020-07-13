#include "BasicDofusBotFrame.h"

bool BasicDofusBotFrame::computeMessage(sp<Message> message, int srcId) {
    sp<SendPacketFailureMessage> spfMsg;
    
    sp<UnknownDofusMessage> udMsg;
    sp<SequenceNumberMessage> snMsg;

    switch (message->getId()) {
    case UnknownDofusMessage::protocolId:
        udMsg = dynamic_pointer_cast<UnknownDofusMessage>(message);
        Logger::write("Got message of unknown id : " + to_string(udMsg->real_id) + "; Length : " + to_string(udMsg->getLength()) + ";", LOG_DEBUG);
        break;
    
    case SequenceNumberRequestMessage::protocolId:
        Logger::write("Received SequenceNumberRequestMessage", LOG_INFO);

        sendSequenceNumberMessage();
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
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    int messageId = it->second;

    switch(messageId) {
    case SequenceNumberMessage::protocolId:
        Logger::write("SequenceNumberMessage sent.", LOG_INFO);
        break;
    default:
        break;
    }

    packetId_to_messageId.erase(it);

    return true;
}

bool BasicDofusBotFrame::handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) {
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    int messageId = it->second;

    switch(messageId) {
    case SequenceNumberMessage::protocolId:
        Logger::write("SequenceNumberMessage could not be sent. Reason : " + message->reason, LOG_INFO);
        this->killBot();
        break;
    default:
        break;
    }

    packetId_to_messageId.erase(it);

    return true;
}

bool BasicDofusBotFrame::sendSequenceNumberMessage() {
    sp<SequenceNumberMessage> snMsg = make_shared<SequenceNumberMessage>(++sequenceNumber);

    if(!snMsg) {
        Logger::write("Cannot build SequenceNumberMessage", LOG_ERROR);
        this->killBot();
        return false;
    }

    if(!sendPacket(snMsg, dofusBotParent->gameServerInfos.connectionId)) {
        Logger::write("Cannot send SequenceNumberMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }

    return true;
}