#include "MovementFrame.h"

bool MovementFrame::setParent(MessagingUnit *parent){
    if(PacketSendingDofusBotFrame::setParent(parent)) {        
        // Sets the authentification manager if the parent is valid
        if(!manager)
            manager = make_shared<MovementManager>();
        
        manager->setBot(dynamic_cast<DofusBotUnit*>(parent));

        if(!dofusBotParent->mapInfos) {
            Logger::write("The bot don't have any initialized map : no movement will be possible.", LOG_WARNING);
        }

        return true;
    }

    return false;
}

bool MovementFrame::computeMessage(sp<Message> message, int srcId) {
    sp<MoveToCellMessage> mtcMsg;
    sp<ChangeToMapMessage> ctmMsg;

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

    case MoveToCellMessage::protocolId:
        mtcMsg = dynamic_pointer_cast<MoveToCellMessage>(message);

        if(dofusBotParent->playedCharacter) {
            if(dofusBotParent->playedCharacter->cellId == mtcMsg->destinationCellId) {
                dofusBotParent->sendSelfMessage(make_shared<PlayerMovementEndedMessage>());
            } else {
                Logger::write("Pathfinding : " + to_string(dofusBotParent->playedCharacter->cellId) + " to " + to_string(mtcMsg->destinationCellId), LOG_INFO);

                // TODO : séparer le findPath de Roleplay & de Fight
                MovementPath movPath = PathFinding::findPath(dofusBotParent->mapInfos, dofusBotParent->playedCharacter->cellId, mtcMsg->destinationCellId, !dofusBotParent->mapInfos->isFight(), true, !dofusBotParent->mapInfos->isFight());
                
                if(movPath.toKeyMovements().size() > 1) {
                    sendGameMapMovementRequestMessage(&movPath);
                } else {
                    dofusBotParent->sendSelfMessage(make_shared<PlayerMovementErrorMessage>());
                }
            }

        } else {
            Logger::write("Cannot pathfind : no played character.", LOG_WARNING);
        }

        break;

    case MoveToTopSideMessage::protocolId:
        if(dofusBotParent->mapInfos && !moveToRandomCellInVector(dofusBotParent->mapInfos->upChangeMapCellsId)) {
            dofusBotParent->sendSelfMessage(make_shared<PlayerMovementErrorMessage>());
        }
        break;
    
    case MoveToBottomSideMessage::protocolId:
        if(dofusBotParent->mapInfos && !moveToRandomCellInVector(dofusBotParent->mapInfos->downChangeMapCellsId)) {
            dofusBotParent->sendSelfMessage(make_shared<PlayerMovementErrorMessage>());
        }
        break;
    
    case MoveToRightSideMessage::protocolId:
        if(dofusBotParent->mapInfos && !moveToRandomCellInVector(dofusBotParent->mapInfos->rightChangeMapCellsId)) {
            dofusBotParent->sendSelfMessage(make_shared<PlayerMovementErrorMessage>());
        }
        break;
    
    case MoveToLeftSideMessage::protocolId:
        if(dofusBotParent->mapInfos && !moveToRandomCellInVector(dofusBotParent->mapInfos->leftChangeMapCellsId)) {
            dofusBotParent->sendSelfMessage(make_shared<PlayerMovementErrorMessage>());
        }
        break;
    
    case ChangeToMapMessage::protocolId:
        ctmMsg = dynamic_pointer_cast<ChangeToMapMessage>(message);
        sendChangeMapMessage(ctmMsg->mapId);
        break;
        
    default:
        return false;
    }
    
    return true;
}

bool MovementFrame::handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) {
    // Checks if the message was sent by this frame
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    // If so, gets the mapped message id
    int messageId = it->second;

    // Logs what message has been sent and changes Frame's state if needed
    switch (messageId)
    {
    case GameMapMovementRequestMessage::protocolId:
        Logger::write("GameMapMovementRequestMessage sent.", LOG_INFO);
        break;
    
    case ChangeMapMessage::protocolId:
        Logger::write("ChangeMapMessage sent.", LOG_INFO);
        break;
    
    default:
        Logger::write("Message of id " + to_string(messageId) + " was successfully sent.", LOG_INFO);
        break;
    }

    packetId_to_messageId.erase(it);

    return true;
}

bool MovementFrame::handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) {
    // Checks if the message was sent by this frame
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    // If so, gets the mapped message id
    int messageId = it->second;

    // Logs what message could not be sent and kills bot if needed
    switch (messageId)
    {
    case GameMapMovementRequestMessage::protocolId:
        Logger::write("GameMapMovementRequestMessage could not be sent.", LOG_WARNING);
        // A voir si bot kill
        break;
    
    case ChangeMapMessage::protocolId:
        Logger::write("ChangeMapMessage could not be sent.", LOG_WARNING);
        // A voir si bot kill
        break;
    
    default:
        Logger::write("Message of id " + to_string(messageId) + " was could not be sent. Reason : " + message->reason, LOG_WARNING);
        // A voir si bot kill
        break;
    }

    packetId_to_messageId.erase(it);

    return true;
}

bool MovementFrame::moveToRandomCellInVector(vector<int> cells) {
    if(!manager) {
        Logger::write("Cannot move wihtout a Movement Manager", LOG_ERROR);
        return false;
    }

    int destId = manager->pathfindToCellInVectorRandom(cells);
    if(destId != -1) {
        dofusBotParent->sendSelfMessage(make_shared<MoveToCellMessage>(destId));
        return true;
    } else {
        Logger::write("Cannot pathfind to any available cell.", LOG_WARNING);
    }

    return false;

}

bool MovementFrame::sendGameMapMovementRequestMessage(MovementPath* path) {
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

bool MovementFrame::sendChangeMapMessage(double mapId) {
    sp<ChangeMapMessage> cmmMsg(new ChangeMapMessage());

    if(!cmmMsg) {
        Logger::write("Cannot build ChangeMapMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }

    cmmMsg->mapId = mapId;

    if(!sendPacket(cmmMsg, dofusBotParent->gameServerInfos.connectionId)) {
        Logger::write("Cannot send ChangeMapMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }

    return true;
}

/*
    // case PlayerMoved::protocolId:
    //     if(currentState == mfs_changingmap) {
    //         // dofusBotParent->
    //         sp<ChangeMapMessage> cmMsg(new ChangeMapMessage());
    //         cmMsg->mapId = newMapId;

    //         sendPacket(cmMsg, dofusBotParent->gameServerInfos.connectionId);
    //         currentState = mfs_idle;

    //         Logger::write("Changing to map : " + to_string(cmMsg->mapId), LOG_INFO);
    //     } else if (currentState == mfs_pathfindToIron) {
    //         // Attention : plein de problèmes. A ne pas copier (enfin pas tout)
    //         if(dofusBotParent->playedCharacter->cellId == destCellId) {
    //             sp<InteractiveUseRequestMessage> iurMsg(new InteractiveUseRequestMessage());
    //             iurMsg->elemId = elementId;
    //             iurMsg->skillInstanceUid = skillId;

    //             sendPacket(iurMsg, dofusBotParent->gameServerInfos.connectionId);
    //             currentState = mfs_mining;

    //             Logger::write("Begin mining", LOG_INFO);
    //         } else {
    //             currentState = mfs_idle;
    //             Logger::write("Cannot pathfind to iron.", LOG_INFO);
    //         }
    //     }
    //     message->keepInLoop = true;
    //     return true;
        // return false;


*/