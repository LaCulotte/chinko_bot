#include "FightActionFrame.h"

bool FightActionFrame::computeMessage(sp<Message> message, int srcId) {
    sp<CastSpellOnCellMessage> cosMsg;
    sp<MoveToCellMessage> mtcMsg;

    sp<GameFightReadyMessage> gfrMsg;

    switch (message->getId())
    {
    case SendPacketSuccessMessage::protocolId:
        if(!handleSendPacketSuccessMessage(dynamic_pointer_cast<SendPacketSuccessMessage>(message)))
            return false;

        break;

    case SendPacketFailureMessage::protocolId:
        if(!handleSendPacketFailureMessage(dynamic_pointer_cast<SendPacketFailureMessage>(message)))
            return false;

        break;

    case CastSpellOnCellMessage::protocolId:
        // Casts spell 
        cosMsg = dynamic_pointer_cast<CastSpellOnCellMessage>(message);
        this->sendGameActionFightCastRequestMessage(cosMsg->cellId, cosMsg->spellId);
        break;

    case MoveToCellMessage::protocolId:
        mtcMsg = dynamic_pointer_cast<MoveToCellMessage>(message);

        if(dofusBotParent->playedCharacter) {
            // Gets played character
            if(dofusBotParent->playedCharacter->cellId == mtcMsg->destinationCellId) {
                dofusBotParent->sendSelfMessage(make_shared<FightActionFailureMessage>());
            } else {
                Logger::write("Pathfinding : " + to_string(dofusBotParent->playedCharacter->cellId) + " to " + to_string(mtcMsg->destinationCellId), LOG_INFO);
                
                // Specific pathfind for the battle
                MovementPath movPath = PathFinding::findPath(dofusBotParent->mapInfos, dofusBotParent->playedCharacter->cellId, mtcMsg->destinationCellId, false, true, false);
                
                // Sends the path if it is valid
                if(movPath.toKeyMovements().size() > 1) {
                    sendGameMapMovementRequestMessage(&movPath);
                } else {
                    dofusBotParent->sendSelfMessage(make_shared<FightActionFailureMessage>());
                }
            }

        } else {
            Logger::write("Cannot pathfind : no played character.", LOG_WARNING);
        }

        break;

    case GetFightReadyMessage::protocolId:
        // Gets character ready
        Logger::write("Getting ready.", LOG_INFO);
        gfrMsg = make_shared<GameFightReadyMessage>();
        gfrMsg->isReady = true;
        sendPacket(gfrMsg, dofusBotParent->gameServerInfos.connectionId);
        break;

    case EndTurnMessage::protocolId:
        // Ends player's turn
        Logger::write("Ending turn.", LOG_INFO);
        sendPacket(make_shared<GameFightTurnFinishMessage>(), dofusBotParent->gameServerInfos.connectionId);
        break;
    
    default:
        return false;
    }

    return true;
}

bool FightActionFrame::handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message){
    // Checks if the message was sent by this frame
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    // If so, gets the mapped message id
    int messageId = it->second;

    // Logs what message has been sent and changes Frame's state if needed
    switch (messageId)
    {    
    case GameActionFightCastRequestMessage::protocolId:
        Logger::write("GameActionFightCastRequestMessage was successfully sent.", LOG_INFO);
        break;

    default:
        Logger::write("Message of id " + to_string(messageId) + " was successfully sent.", LOG_INFO);
        break;
    }

    packetId_to_messageId.erase(it);

    return true;
}

bool FightActionFrame::handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) {
    // Checks if the message was sent by this frame
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    // If so, gets the mapped message id
    int messageId = it->second;

    // Logs what message could not be sent and kills bot if needed
    switch (messageId)
    {    
    case GameActionFightCastRequestMessage::protocolId:
        Logger::write("GameActionFightCastRequestMessage could not be sent. Reason : " + message->reason, LOG_WARNING);
        break;

    default:
        Logger::write("Message of id " + to_string(messageId) + " was could not be sent. Reason : " + message->reason, LOG_WARNING);
        // A voir si bot kill
        break;
    }

    packetId_to_messageId.erase(it);

    return true;
}

bool FightActionFrame::sendGameActionFightCastRequestMessage(int cellId, int spellId) {
    sp<GameActionFightCastRequestMessage> gafcrMsg(new GameActionFightCastRequestMessage());

    if(!gafcrMsg) {
        Logger::write("Cannot build GameActionFightCastRequestMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }

    gafcrMsg->cellId = cellId;
    gafcrMsg->spellId = spellId;

    if(!sendPacket(gafcrMsg, dofusBotParent->gameServerInfos.connectionId)) {
        Logger::write("Cannot send GameActionFightCastRequestMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }

    return true;
}

bool FightActionFrame::sendGameMapMovementRequestMessage(MovementPath* path) {
    sp<GameMapMovementRequestMessage> gmmrMsg(new GameMapMovementRequestMessage());

    if(!gmmrMsg) {
        Logger::write("Cannot build GameMapMovementRequestMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }
    
    gmmrMsg->keyMovements = path->toKeyMovements();
    // mapInfos == nullptr n'est pas possible car on entre jamais ici si len(path) < 1
    gmmrMsg->mapId = dofusBotParent->mapInfos->mapId;

    if(!sendPacket(gmmrMsg, dofusBotParent->gameServerInfos.connectionId)) {
        Logger::write("Cannot send GameMapMovementRequestMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }

    return true;
}
