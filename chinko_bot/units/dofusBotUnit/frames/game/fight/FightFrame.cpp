#include "FightFrame.h"

bool FightFrame::computeMessage(sp<Message> message, int srcId) {

    sp<GameFightStartingMessage> gfsMsg;
    sp<GameFightJoinMessage> gfjMsg;

    sp<GameFightTurnStartMessage> gftsMsg;

    // TO REMOVE
    sp<GameRolePlayPlayerFightFriendlyRequestedMessage> grpffrMsg;
    sp<GameRolePlayPlayerFightFriendlyAnswerMessage> grpffaMsg;
    
    switch (message->getId()) {
    case SendPacketSuccessMessage::protocolId:
        // Handles SendPacketSuccessMessage
        if(!handleSendPacketSuccessMessage(dynamic_pointer_cast<SendPacketSuccessMessage>(message)))
            return false;
        
        break;

    case SendPacketFailureMessage::protocolId:
        // Handles SendPacketFailureMessage
        if(!handleSendPacketFailureMessage(dynamic_pointer_cast<SendPacketFailureMessage>(message)))
            return false;
        
        break;

    // case GameFightStartingMessage::protocolId:
    //     gfsMsg = dynamic_pointer_cast<GameFightStartingMessage>(message);
    //     // gfsMsg->fightId
    //     Logger::write("Fight (" + to_string(gfsMsg->fightId) + ") of type " + to_string(gfsMsg->fightType) + " started.", LOG_INFO);
    //     break;

    // case GameFightJoinMessage::protocolId:
    //     gfjMsg = dynamic_pointer_cast<GameFightJoinMessage>(message);
    //     Logger::write("Fight starting in " + to_string(gfjMsg->timeMaxBeforeFightStart) + ".", LOG_INFO);
    //     break;

    // case GameEntitiesDispositionMessage::protocolId:
    //     Logger::write("GameEntitiesDispositionMessage received", LOG_DEBUG);
    //     break;

    // case GameFightShowFighterMessage::protocolId:
    //     Logger::write("GameFightShowFighterMessage received.", LOG_DEBUG);
    //     break;
        
    // case GameFightUpdateTeamMessage::protocolId:
    //     Logger::write("GameFightUpdateTeamMessage received.", LOG_DEBUG);
    //     break;
        
    // TO REMOVE
    case GameRolePlayPlayerFightFriendlyRequestedMessage::protocolId:
        grpffrMsg = dynamic_pointer_cast<GameRolePlayPlayerFightFriendlyRequestedMessage>(message);
        Logger::write("Friendly fight engaged with entity " + to_string(grpffrMsg->sourceId) + ".", LOG_INFO);

        grpffaMsg = make_shared<GameRolePlayPlayerFightFriendlyAnswerMessage>();
        grpffaMsg->accept = true;
        grpffaMsg->fightId = grpffrMsg->fightId;
        sendPacket(grpffaMsg, dofusBotParent->gameServerInfos.connectionId);
        break;

    default:
        return false;
    }
    
    return true;
}

bool FightFrame::handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) {
    // Checks if the message was sent by this frame
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    // If so, gets the mapped message id
    int messageId = it->second;

    // Logs what message could not be sent and kills bot if needed
    switch (messageId) {
    default:
        Logger::write("Message of id " + to_string(messageId) + " was sent.", LOG_INFO);

    }

    packetId_to_messageId.erase(it);

    return true;
}

bool FightFrame::handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) {
    // Checks if the message was sent by this frame
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    // If so, gets the mapped message id
    int messageId = it->second;

    // Logs what message could not be sent and kills bot if needed
    switch (messageId) {
    default:
        Logger::write("Message of id " + to_string(messageId) + " could not be sent. Reason : " + message->reason, LOG_WARNING);
    }

    packetId_to_messageId.erase(it);

    return true;
}