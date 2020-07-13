#include "BasicDofusBotFrame.h"

bool BasicDofusBotFrame::computeMessage(sp<Message> message, int srcId) {
    sp<SendPacketFailureMessage> spfMsg;
    
    sp<UnknownDofusMessage> udMsg;
    sp<SequenceNumberMessage> snMsg;

    switch (message->getId()) {
    case UnknownDofusMessage::protocolId:
        // Logs if an unknown message has been recceived
        udMsg = dynamic_pointer_cast<UnknownDofusMessage>(message);
        Logger::write("Got message of unknown id : " + to_string(udMsg->real_id) + "; Length : " + to_string(udMsg->getLength()) + ";", LOG_DEBUG);
        break;
    
    case SequenceNumberRequestMessage::protocolId:
        // Sends sequence number when servers sends a request 
        Logger::write("Received SequenceNumberRequestMessage", LOG_INFO);

        sendSequenceNumberMessage();
        break;

    case SendPacketSuccessMessage::protocolId:
        // Handles SendPacketSuccessMessage
        if(handleSendPacketSuccessMessage(dynamic_pointer_cast<SendPacketSuccessMessage>(message)))
            break;

        return false;

    case SendPacketFailureMessage::protocolId:
        // Handles SendPacketFailureMessage
        if(handleSendPacketFailureMessage(dynamic_pointer_cast<SendPacketFailureMessage>(message)))
            break;

        return false;

    default:
        return false;
    }

    return true;
}

bool BasicDofusBotFrame::handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) {
    // Checks if the message was sent by this frame
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    // If so, gets the mapped message id
    int messageId = it->second;

    // Logs what message has been sent
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
    // Checks if the message was sent by this frame
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    // If so, gets the mapped message id
    int messageId = it->second;

    // Logs what message could not be sent
    switch(messageId) {
    case SequenceNumberMessage::protocolId:
        Logger::write("SequenceNumberMessage could not be sent. Reason : " + message->reason, LOG_INFO);
        // Kills the bot
        this->killBot();
        break;
    default:
        break;
    }

    packetId_to_messageId.erase(it);

    return true;
}

bool BasicDofusBotFrame::sendSequenceNumberMessage() {
    // Builds SequenceNumber message
    sp<SequenceNumberMessage> snMsg = make_shared<SequenceNumberMessage>(++sequenceNumber);

    // Checks if it is valid
    if(!snMsg) {
        // If not, logs it and kills the bot
        Logger::write("Cannot build SequenceNumberMessage", LOG_ERROR);
        this->killBot();
        return false;
    }

    // Checks if it can be sent
    if(!sendPacket(snMsg, dofusBotParent->gameServerInfos.connectionId)) {
        // If not, logs it and kills the bot
        Logger::write("Cannot send SequenceNumberMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }

    // All is good in the world
    return true;
}