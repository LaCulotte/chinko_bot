#include "BasicActionsFrame.h"

#include "InteractiveCollectedMessage.h"
#include "NoInteractiveToCollectMessage.h"

#include "InteractiveUseErrorMessage.h"

bool BasicActionsFrame::computeMessage(sp<Message> message, int srcId) {
    sp<ChangeToUpMapMessage>    ctuMsg;
    sp<ChangeToDownMapMessage>  ctdMsg;
    sp<ChangeToRightMapMessage> ctrMsg;
    sp<ChangeToLeftMapMessage>  ctlMsg;
    
    switch(message->getId()) {
    case ChangeToUpMapMessage::protocolId:
        ctuMsg = dynamic_pointer_cast<ChangeToUpMapMessage>(message);
        if(currentState == baf_idle && dofusBotParent->mapInfos) {
            dofusBotParent->sendSelfMessage(make_shared<MoveToTopSideMessage>(ctuMsg->floor));
            changeMapId = dofusBotParent->mapInfos->upMapId;
            currentState = baf_pathfindToSide;
        }
        break;

    case ChangeToDownMapMessage::protocolId:
        ctdMsg = dynamic_pointer_cast<ChangeToDownMapMessage>(message);
        if(currentState == baf_idle && dofusBotParent->mapInfos) {
            dofusBotParent->sendSelfMessage(make_shared<MoveToBottomSideMessage>(ctdMsg->floor));
            changeMapId = dofusBotParent->mapInfos->downMapId;
            currentState = baf_pathfindToSide;
        }
        break;

    case ChangeToRightMapMessage::protocolId:
        ctrMsg = dynamic_pointer_cast<ChangeToRightMapMessage>(message);
        if(currentState == baf_idle && dofusBotParent->mapInfos) {
            dofusBotParent->sendSelfMessage(make_shared<MoveToRightSideMessage>(ctrMsg->floor));
            changeMapId = dofusBotParent->mapInfos->rightMapId;
            currentState = baf_pathfindToSide;
        }
        break;

    case ChangeToLeftMapMessage::protocolId:
        ctlMsg = dynamic_pointer_cast<ChangeToLeftMapMessage>(message);
        if(currentState == baf_idle && dofusBotParent->mapInfos) {
            dofusBotParent->sendSelfMessage(make_shared<MoveToLeftSideMessage>(ctlMsg->floor));
            changeMapId = dofusBotParent->mapInfos->leftMapId;
            currentState = baf_pathfindToSide;
        }
        break;

    case PlayerMovementEndedMessage::protocolId:
        if(currentState == baf_pathfindToSide) {
            dofusBotParent->sendSelfMessage(make_shared<ChangeToMapMessage>(changeMapId));
            currentState = baf_changeMap;
        } else if (currentState == baf_pathfindToCollect) {
            if(sendInteractiveUseRequestMessage(elementToCollectId, skillToUseId))
                currentState = baf_collect;
            else 
                currentState = baf_idle;
        } else if (currentState == baf_pathfindToMonster) {
            sendGameRolePlayAttackMonsterRequestMessage(monsterId);
            currentState = baf_idle;            
        }
        break;

    case InteractiveUseEndedMessage::protocolId:
        if(currentState == baf_collect) {
            currentState = baf_idle;
            Logger::write("Successfully collected", LOG_INFO);
            // TODO : avec elementTypeId
            dofusBotParent->sendSelfMessage(make_shared<InteractiveCollectedMessage>());
        } else {
            Logger::write("Received an InteractiveUsedMessage while not using interactive?", LOG_WARNING);
        }
        break;

    case InteractiveUseErrorMessage::protocolId:
        if(currentState == baf_collect) {
            currentState = baf_idle;
            Logger::write("Cannot collect.", LOG_INFO);
            // TODO : avec elementTypeId
            dofusBotParent->sendSelfMessage(make_shared<NoInteractiveToCollectMessage>());
        } else {
            Logger::write("Received an InteractiveUsedMessage while not using interactive?", LOG_WARNING);
        }        
        break;

    case PlayerMovementErrorMessage::protocolId:
        if(currentState == baf_pathfindToSide || currentState == baf_pathfindToCollect) {
            currentState = baf_idle;
            Logger::write("Impossible to change map.", LOG_WARNING);
        } else if (currentState == baf_pathfindToCollect) {
            currentState = baf_idle;
            Logger::write("Cannot pathfind to interactive", LOG_WARNING);
            // TODO : avec elementTypeId
            dofusBotParent->sendSelfMessage(make_shared<NoInteractiveToCollectMessage>());
        }
        break;

    case CurrentMapChangedMessage::protocolId:
        inaccessibleElements.clear();
        currentState = baf_idle;
        break;

    case CollectInteractiveTypeIdMessage::protocolId:
        if(currentState == baf_idle && dofusBotParent->getMapInfosAsRoleplay()) {
            int elementTypeId = dynamic_pointer_cast<CollectInteractiveTypeIdMessage>(message)->elementTypeId;
            if(!collectElementOfTypeId(elementTypeId))
                dofusBotParent->sendSelfMessage(make_shared<NoInteractiveToCollectMessage>(elementTypeId));
        }
        break;

    case AttackMonsterGroupMessage::protocolId:
        if(currentState == baf_idle && dofusBotParent->getMapInfosAsRoleplay()) {
            monsterId = dynamic_pointer_cast<AttackMonsterGroupMessage>(message)->monsterGroupId;
            sp<ActorData> monsterGroupData = dofusBotParent->getMapInfosAsRoleplay()->getMonsterGroup(monsterId);

            if(monsterGroupData) {
                dofusBotParent->sendSelfMessage(make_shared<MoveToCellMessage>(monsterGroupData->cellId));
                currentState = baf_pathfindToMonster;
            } else {
                Logger::write("No monster of id " + to_string(monsterId), LOG_ERROR);
                monsterId = 0;
            }         
        }
        break;
    
    default:
        return false;
    }

    return true;
}

bool BasicActionsFrame::collectElementOfTypeId(int elementTypeId) {
    for (auto interactiveElementIt : dofusBotParent->getMapInfosAsRoleplay()->interactiveElements) {
        // auto interactiveElement = interactiveElementIt.second;
        if(interactiveElementIt.second->elementTypeId == elementTypeId && interactiveElementIt.second->onCurrentMap && interactiveElementIt.second->enabledSkills.size() > 0 && inaccessibleElements.find(interactiveElementIt.second->elementId) == inaccessibleElements.end()) {
            auto statedElement = dofusBotParent->getMapInfosAsRoleplay()->statedElements[interactiveElementIt.second->elementId];
            if(statedElement.elementState == 0) {
                if(collectElement(statedElement.elementId))
                    return true;
            }
        }
    }

    Logger::write("No element of id " + to_string(elementTypeId) + " is currently available", LOG_WARNING);

    return false;
}

bool BasicActionsFrame::collectElement(int elementId) {
    auto interactiveElement = dofusBotParent->getMapInfosAsRoleplay()->interactiveElements[elementId];
    auto statedElement = dofusBotParent->getMapInfosAsRoleplay()->statedElements[elementId];
    
    MovementPath movPath = PathFinding::findPath(dofusBotParent->mapInfos, dofusBotParent->playedCharacter->cellId, statedElement.elementCellId);

    // if(movPath)
    int lastCellId = movPath.toKeyMovements().back() & 0xFFF;

    int dX = abs(dofusBotParent->mapInfos->cellId_to_XPosition(statedElement.elementCellId) - dofusBotParent->mapInfos->cellId_to_XPosition(lastCellId)); 
    int dY = abs(dofusBotParent->mapInfos->cellId_to_YPosition(statedElement.elementCellId) - dofusBotParent->mapInfos->cellId_to_YPosition(lastCellId)); 

    if(dX < 2 && dY < 2) {
        dofusBotParent->sendSelfMessage(make_shared<MoveToCellMessage>(statedElement.elementCellId));
        elementToCollectId = elementId;
        skillToUseId = interactiveElement->enabledSkills[0]->skillInstanceUid;
        currentState = baf_pathfindToCollect;
        return true;
    }

    inaccessibleElements.insert(elementId);
    return false;
}

bool BasicActionsFrame::sendInteractiveUseRequestMessage(int elementId, int skillId) {
    sp<InteractiveUseRequestMessage> iurMsg(new InteractiveUseRequestMessage());

    if(!iurMsg) {
        Logger::write("Cannot build InteractiveUseRequestMessage.", LOG_ERROR);
        return false;
    }

    iurMsg->elemId = elementId;
    iurMsg->skillInstanceUid = skillId;

    if(!sendPacket(iurMsg, dofusBotParent->gameServerInfos.connectionId)) {
        Logger::write("Cannot send InteractiveUseRequestMessage.", LOG_ERROR);
        return false;
    }
    
    return true;
}

bool BasicActionsFrame::sendGameRolePlayAttackMonsterRequestMessage(double monsterGroupId) {
    sp<GameRolePlayAttackMonsterRequestMessage> grpamrMsg(new GameRolePlayAttackMonsterRequestMessage());

    if(!grpamrMsg) {
        Logger::write("Cannot build InteractiveUseRequestMessage.", LOG_ERROR);
        return false;
    }

    grpamrMsg->monsterGroupId = monsterGroupId;

    if(!sendPacket(grpamrMsg, dofusBotParent->gameServerInfos.connectionId)) {
        Logger::write("Cannot send InteractiveUseRequestMessage.", LOG_ERROR);
        return false;
    }
    
    return true;
}