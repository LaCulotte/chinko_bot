#include "BasicActionsFrame.h"

#include "InteractiveCollectedMessage.h"
#include "NoInteractiveToCollectMessage.h"

#include "InteractiveUseErrorMessage.h"

#include "TimedMessage.h"
#include "SendUseRequestMessage.h"

bool BasicActionsFrame::computeMessage(sp<Message> message, int srcId) {
    sp<ChangeToUpMapMessage>    ctuMsg;
    sp<ChangeToDownMapMessage>  ctdMsg;
    sp<ChangeToRightMapMessage> ctrMsg;
    sp<ChangeToLeftMapMessage>  ctlMsg;
    
    switch(message->getId()) {
    case ChangeToUpMapMessage::protocolId:
        ctuMsg = dynamic_pointer_cast<ChangeToUpMapMessage>(message);
        if(currentState == baf_idle && dofusBotParent->mapInfos) {
            // Moves to the up side of the map
            dofusBotParent->sendSelfMessage(make_shared<MoveToTopSideMessage>(ctuMsg->floor));
            // Stores the map to change to
            changeMapId = dofusBotParent->mapInfos->upMapId;
            currentState = baf_pathfindToSide;
        }
        break;

    case ChangeToDownMapMessage::protocolId:
        ctdMsg = dynamic_pointer_cast<ChangeToDownMapMessage>(message);
        if(currentState == baf_idle && dofusBotParent->mapInfos) {
            // Moves to the down side of the map
            dofusBotParent->sendSelfMessage(make_shared<MoveToBottomSideMessage>(ctdMsg->floor));
            // Stores the map to change to
            changeMapId = dofusBotParent->mapInfos->downMapId;
            currentState = baf_pathfindToSide;
        }
        break;

    case ChangeToRightMapMessage::protocolId:
        ctrMsg = dynamic_pointer_cast<ChangeToRightMapMessage>(message);
        if(currentState == baf_idle && dofusBotParent->mapInfos) {
            // Moves to the right side of the map
            dofusBotParent->sendSelfMessage(make_shared<MoveToRightSideMessage>(ctrMsg->floor));
            // Stores the map to change to
            changeMapId = dofusBotParent->mapInfos->rightMapId;
            currentState = baf_pathfindToSide;
        }
        break;

    case ChangeToLeftMapMessage::protocolId:
        ctlMsg = dynamic_pointer_cast<ChangeToLeftMapMessage>(message);
        if(currentState == baf_idle && dofusBotParent->mapInfos) {
            // Moves to the left side of the map
            dofusBotParent->sendSelfMessage(make_shared<MoveToLeftSideMessage>(ctlMsg->floor));
            // Stores the map to change to
            changeMapId = dofusBotParent->mapInfos->leftMapId;
            currentState = baf_pathfindToSide;
        }
        break;

    case PlayerMovementEndedMessage::protocolId:
        // Does an action at the end of the movement according to the frame's state
        if(currentState == baf_pathfindToSide) {
            dofusBotParent->sendSelfMessage(make_shared<TimedMessage>(make_shared<ChangeToMapMessage>(changeMapId), 500 + (rand() % 500)));
            currentState = baf_changeMap;
        } else if (currentState == baf_pathfindToCollect) {
            dofusBotParent->sendSelfMessage(make_shared<TimedMessage>(make_shared<SendUseRequestMessage>(), 100 + (rand() % 200)));    
        } else if (currentState == baf_pathfindToMonster) {
            sendGameRolePlayAttackMonsterRequestMessage(monsterId);
            currentState = baf_idle;            
        }
        break;

    case SendUseRequestMessage::protocolId:
        if(currentState != baf_pathfindToCollect) {
            Logger::write("Received SendUseRequestMessage while not pathfinding to collect an interactive.", LOG_WARNING);
            break;
        }

        // Used the specified interactive
        if(sendInteractiveUseRequestMessage(elementToCollectId, skillToUseId)) 
            currentState = baf_collect;
        else 
            currentState = baf_idle;
            
        break;

    case InteractiveUseEndedMessage::protocolId:
        if(currentState == baf_collect) {
            currentState = baf_idle;
            Logger::write("Successfully collected", LOG_INFO);
            // TODO : avec elementTypeId
            // Notofies the bot of the end of use
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
            // Notifies the bot of the failure
            dofusBotParent->sendSelfMessage(make_shared<NoInteractiveToCollectMessage>());
        } else {
            Logger::write("Received an InteractiveUsedMessage while not using interactive?", LOG_WARNING);
        }        
        break;

    case PlayerMovementErrorMessage::protocolId:
        if(currentState == baf_pathfindToSide || currentState == baf_pathfindToMonster) {
            currentState = baf_idle;
            Logger::write("Impossible to change map.", LOG_WARNING);
        } else if (currentState == baf_pathfindToCollect) {
            currentState = baf_idle;
            Logger::write("Cannot pathfind to interactive", LOG_WARNING);
            // TODO : avec elementTypeId
            // Notifies the bot of the failure
            dofusBotParent->sendSelfMessage(make_shared<NoInteractiveToCollectMessage>());
        }
        break;

    case CurrentMapChangedMessage::protocolId:
        // Resets frame when the map changes
        inaccessibleElements.clear();
        currentState = baf_idle;
        break;

    case CollectInteractiveTypeIdMessage::protocolId:
        if(currentState == baf_idle && dofusBotParent->getMapInfosAsRoleplay()) {
            int elementTypeId = dynamic_pointer_cast<CollectInteractiveTypeIdMessage>(message)->elementTypeId;
            // Tries to collect an interactive
            if(!collectElementOfTypeId(elementTypeId))
                // If it cannot, notifies the bot
                dofusBotParent->sendSelfMessage(make_shared<NoInteractiveToCollectMessage>(elementTypeId));
        }
        break;

    case AttackMonsterGroupMessage::protocolId:
        if(currentState == baf_idle && dofusBotParent->getMapInfosAsRoleplay()) {
            // Gets monster group
            monsterId = dynamic_pointer_cast<AttackMonsterGroupMessage>(message)->monsterGroupId;
            sp<ActorData> monsterGroupData = dofusBotParent->getMapInfosAsRoleplay()->getMonsterGroup(monsterId);

            if(monsterGroupData) {
                // Pathfinds to the monster group
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

// TODO : faire gaffe à dofusBotParent->getMapInfosAs.. qui peut renvoyer nullptr
bool BasicActionsFrame::collectElementOfTypeId(int elementTypeId) {
    // Searches through all the interactives
    for (auto interactiveElementIt : dofusBotParent->getMapInfosAsRoleplay()->interactiveElements) {
        // If it is a valid & coresponding interactive
        if(interactiveElementIt.second->elementTypeId == elementTypeId && interactiveElementIt.second->onCurrentMap 
            && inaccessibleElements.find(interactiveElementIt.second->elementId) == inaccessibleElements.end()) {

            // Gets corresponding stated element
            auto statedElement = dofusBotParent->getMapInfosAsRoleplay()->statedElements[interactiveElementIt.second->elementId];
            if(statedElement.elementState == 0) {
                // Searches for a skill to use to collect the interactive
                int usedSkillId = -1;
                int usedSkillUID = -1;
                // TODO : loop peut se faire sans indice : on manipules mtn des pointeurs
                for(int i = 0; i < interactiveElementIt.second->enabledSkills.size(); i++) {
                    if(dofusBotParent->characterManager->hasSkill(interactiveElementIt.second->enabledSkills[i]->skillId)) {
                        usedSkillUID = interactiveElementIt.second->enabledSkills[i]->skillInstanceUid;
                        usedSkillId = interactiveElementIt.second->enabledSkills[i]->skillId;
                        break;
                    }
                }

                // Tries to collect the element
                if(usedSkillId != -1 && usedSkillUID != -1 && collectElement(statedElement.elementId, usedSkillId, usedSkillUID))
                    return true;
            }
        }
    }

    Logger::write("No element of id " + to_string(elementTypeId) + " is currently available", LOG_WARNING);

    return false;
}

bool BasicActionsFrame::collectElement(int elementId, int skillId, int skillUID) {
    int range = dofusBotParent->characterManager->getSkillRange(skillId);
    if(range == -1) {
        Logger::write("Skill " + to_string(skillId) + " has no range!", LOG_ERROR);
        return false;        
    }

    // Gets the cell on which to pathfind in order to collect the element; translation of the source code
    sp<RoleplayMapManager> mapInfos = dofusBotParent->getMapInfosAsRoleplay();
    auto interactiveElement = mapInfos->interactiveElements[elementId];
    auto statedElement = mapInfos->statedElements[elementId];

    sp<vector<int>> forbiddenCells = make_shared<vector<int>>();
    for(int i = 0; i < 8; i++) {
        int mpId = mapInfos->getNearestCellInDirection(statedElement.elementCellId, i);
        if(mpId != -1) {
            sp<Cell> mp = mapInfos->getCell(mpId);
            bool forbidden = !mp->mov || mp->farmCell;

            if(!forbidden) {
                int numWalkableCells = 8;
                for(int j = 0; j < 8; j++) {
                    int mp2Id = mapInfos->getNearestCellInDirection(mpId, j);
                    int mp2X = mapInfos->cellId_to_XPosition(mp2Id);
                    int mp2Y = mapInfos->cellId_to_YPosition(mp2Id);

                    if(mp2Id != -1 && (!mapInfos->canMove(mp2Id, mpId) || !mapInfos->canMove(mapInfos->position_to_cellId(mp2X - 1, mp2Y), mpId) && mapInfos->canMove(mapInfos->position_to_cellId(mp2X, mp2Y - 1), mpId)))
                        numWalkableCells--;
                }
                if(numWalkableCells <= 0)
                    forbidden = true;
            }

            if(forbidden)
                forbiddenCells->push_back(mpId);
        }
    }

    sp<Cell> interactiveCell = mapInfos->getCell(statedElement.elementCellId);
    int minRange = 1;
    // Pour le futur : si autres interactions, minRange ne sera pas toujours 1 => impact sur la suite du programme : voir RoleplayWorldFrame
    // for(sp<InteractiveElementSkill> skill : interactiveElement->enabledSkills) {

    // }

    int distanceElementToPlayer = mapInfos->getManhattanDistance(statedElement.elementCellId, dofusBotParent->playedCharacter->cellId);
    int destinationCellId = -1;
    if(distanceElementToPlayer <= 1 && (!interactiveCell->mov || interactiveCell->farmCell)) {
        destinationCellId = dofusBotParent->playedCharacter->cellId;
    } else {
        int dir = mapInfos->getAdvancedOrientation(statedElement.elementCellId, dofusBotParent->playedCharacter->cellId);
        destinationCellId = mapInfos->getNearestFreeCellInDirection(statedElement.elementCellId, dir, true, true, false, forbiddenCells);
    }

    if(destinationCellId == -1 || find(forbiddenCells->begin(), forbiddenCells->end(), destinationCellId) != forbiddenCells->end())
        destinationCellId = statedElement.elementCellId;

    
    MovementPath movPath = PathFinding::findPath(dofusBotParent->mapInfos, dofusBotParent->playedCharacter->cellId, destinationCellId);

    // Gets the last cell when pathfinding to the destination
    int lastCellId = 0;
    if(destinationCellId == dofusBotParent->playedCharacter->cellId)
        lastCellId = movPath.toKeyMovements().back() & 0xFFF;
    else 
        lastCellId = destinationCellId;

    int dX = abs(dofusBotParent->mapInfos->cellId_to_XPosition(destinationCellId) - dofusBotParent->mapInfos->cellId_to_XPosition(lastCellId)); 
    int dY = abs(dofusBotParent->mapInfos->cellId_to_YPosition(destinationCellId) - dofusBotParent->mapInfos->cellId_to_YPosition(lastCellId)); 

    // If it is a valid cell, pathfinds to it then collects it
    if(dX + dY <= range) {
        dofusBotParent->sendSelfMessage(make_shared<MoveToCellMessage>(destinationCellId));
        elementToCollectId = elementId;
        skillToUseId = skillUID;
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