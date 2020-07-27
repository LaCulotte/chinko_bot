#include "MovementFrame.h"

bool MovementFrame::setParent(MessagingUnit *parent){
    if(PacketSendingDofusBotFrame::setParent(parent)) {        
        // Sets the authentification manager if the parent is valid
        if(!manager)
            manager = make_shared<MovementManager>();
        
        manager->setBot(dynamic_cast<DofusBotUnit*>(parent));

        return true;
    }

    return false;
}

bool MovementFrame::computeMessage(sp<Message> message, int srcId) {
    sp<MoveToCellMessage> mtcMsg;

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

        if(dofusBotParent->playedCharacer) {
            Logger::write("Pathfinding : " + to_string(dofusBotParent->playedCharacer->cellId) + " to " + to_string(mtcMsg->destinationCellId), LOG_INFO);
            MovementPath movPath = PathFinding::findPath(&dofusBotParent->mapInfos, dofusBotParent->playedCharacer->cellId, mtcMsg->destinationCellId);
            
            if(movPath.toKeyMovements().size() > 0) {
                sp<GameMapMovementRequestMessage> gmmrMsg(new GameMapMovementRequestMessage());
                gmmrMsg->keyMovements = movPath.toKeyMovements();
                gmmrMsg->mapId = dofusBotParent->mapInfos.getMapId();
                sendPacket(gmmrMsg, dofusBotParent->gameServerInfos.connectionId);

                // for(auto key : gmmrMsg->keyMovements) {
                //     cout << dofusBotParent->mapInfos.cellId_to_XPosition(key & 0xFFF) << "; " << dofusBotParent->mapInfos.cellId_to_YPosition(key & 0xFFF) << endl;
                // }
            }
        } else {
            Logger::write("Cannot pathfind : no played character.", LOG_WARNING);
        }

        break;
    
    case ChangeToRightMapMessage::protocolId:
        // manager
        if(!manager) {
            Logger::write("Cannot change map : no MovementManager.", LOG_ERROR);
            break;
        }
        {
            int destId = manager->pathfindToCellInVectorRandom(dofusBotParent->mapInfos.rightChangeMapCellsId);
            if(destId != -1) {
                dofusBotParent->sendSelfMessage(make_shared<MoveToCellMessage>(destId));
                newMapId = dofusBotParent->mapInfos.rightMapId;
                currentState = mfs_changingmap;
            } else {
                Logger::write("Cannot move to right map.", LOG_WARNING);
            }
        }
        break;

    case ChangeToLeftMapMessage::protocolId:
        // manager
        if(!manager) {
            Logger::write("Cannot change map : no MovementManager.", LOG_ERROR);
            break;
        }
        {
            int destId = manager->pathfindToCellInVectorRandom(dofusBotParent->mapInfos.leftChangeMapCellsId);
            if(destId != -1) {
                dofusBotParent->sendSelfMessage(make_shared<MoveToCellMessage>(destId));
                newMapId = dofusBotParent->mapInfos.leftMapId;
                currentState = mfs_changingmap;
            } else {
                Logger::write("Cannot move to left map.", LOG_WARNING);
            }
        }
        break;

    case ChangeToUpMapMessage::protocolId:
        // manager
        if(!manager) {
            Logger::write("Cannot change map : no MovementManager.", LOG_ERROR);
            break;
        }
        {
            int destId = manager->pathfindToCellInVectorRandom(dofusBotParent->mapInfos.upChangeMapCellsId);
            if(destId != -1) {
                dofusBotParent->sendSelfMessage(make_shared<MoveToCellMessage>(destId));
                newMapId = dofusBotParent->mapInfos.upMapId;
                currentState = mfs_changingmap;
            } else {
                Logger::write("Cannot move to up map.", LOG_WARNING);
            }
        }
        break;

    case ChangeToDownMapMessage::protocolId:
        // manager
        if(!manager) {
            Logger::write("Cannot change map : no MovementManager.", LOG_ERROR);
            break;
        }
        {
            int destId = manager->pathfindToCellInVectorRandom(dofusBotParent->mapInfos.downChangeMapCellsId);
            if(destId != -1) {
                dofusBotParent->sendSelfMessage(make_shared<MoveToCellMessage>(destId));
                newMapId = dofusBotParent->mapInfos.downMapId;
                currentState = mfs_changingmap;
            } else {
                Logger::write("Cannot move to down map.", LOG_WARNING);
            }
        }
        break;

    case PlayerMoved::protocolId:
        if(currentState == mfs_changingmap) {
            // dofusBotParent->
            sp<ChangeMapMessage> cmMsg(new ChangeMapMessage());
            cmMsg->mapId = newMapId;

            sendPacket(cmMsg, dofusBotParent->gameServerInfos.connectionId);
            currentState = mfs_idle;

            Logger::write("Changing to map : " + to_string(cmMsg->mapId), LOG_INFO);
        }
        message->keepInLoop = true;
        return true;
        // break;
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
    
    default:
        Logger::write("Message of id " + to_string(messageId) + " was could not be sent. Reason : " + message->reason, LOG_WARNING);
        // A voir si bot kill
        break;
    }

    packetId_to_messageId.erase(it);

    return true;
}