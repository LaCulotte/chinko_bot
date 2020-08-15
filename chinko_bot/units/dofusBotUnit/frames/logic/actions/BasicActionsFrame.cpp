#include "BasicActionsFrame.h"

bool BasicActionsFrame::computeMessage(sp<Message> message, int srcId) {

    switch(message->getId()) {
    case ChangeToUpMapMessage::protocolId:
        if(currentState == baf_idle) {
            dofusBotParent->sendSelfMessage(make_shared<MoveToTopSideMessage>());
            changeMapId = dofusBotParent->mapInfos.upMapId;
            currentState = baf_pathfindToSide;
        }
        break;

    case ChangeToDownMapMessage::protocolId:
        if(currentState == baf_idle) {
            dofusBotParent->sendSelfMessage(make_shared<MoveToBottomSideMessage>());
            changeMapId = dofusBotParent->mapInfos.downMapId;
            currentState = baf_pathfindToSide;
        }
        break;

    case ChangeToRightMapMessage::protocolId:
        if(currentState == baf_idle) {
            dofusBotParent->sendSelfMessage(make_shared<MoveToRightSideMessage>());
            changeMapId = dofusBotParent->mapInfos.rightMapId;
            currentState = baf_pathfindToSide;
        }
        break;

    case ChangeToLeftMapMessage::protocolId:
        if(currentState == baf_idle) {
            dofusBotParent->sendSelfMessage(make_shared<MoveToLeftSideMessage>());
            changeMapId = dofusBotParent->mapInfos.leftMapId;
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
        }
        break;

    case InteractiveUseEndedMessage::protocolId:
        if(currentState == baf_collect) {
            currentState = baf_idle;
            Logger::write("Successfully collected", LOG_INFO);
        } else {
            Logger::write("Received an InteractiveUsedMessage while not using interactive?", LOG_WARNING);
        }
        break;

    case PlayerMovementErrorMessage::protocolId:
        if(currentState == baf_pathfindToSide || currentState == baf_pathfindToCollect) {
            currentState = baf_idle;
            Logger::write("Impossible to change map.", LOG_WARNING);
        }
        break;

    case CurrentMapChangedMessage::protocolId:
        inaccessibleElements.clear();
        currentState = baf_idle;
        break;

    case CollectInteractiveTypeIdMessage::protocolId:
        if(currentState == baf_idle) {
            collectElementOfTypeId(dynamic_pointer_cast<CollectInteractiveTypeIdMessage>(message)->elementTypeId);
        }
        break;
    
    default:
        return false;
    }

    return true;
}

void BasicActionsFrame::collectElementOfTypeId(int elementTypeId) {
    for (auto interactiveElementIt : dofusBotParent->mapInfos.interactiveElements) {
        // auto interactiveElement = interactiveElementIt.second;
        if(interactiveElementIt.second->elementTypeId == elementTypeId && interactiveElementIt.second->onCurrentMap && interactiveElementIt.second->enabledSkills.size() > 0 && inaccessibleElements.find(interactiveElementIt.second->elementId) == inaccessibleElements.end()) {
            auto statedElement = dofusBotParent->mapInfos.statedElements[interactiveElementIt.second->elementId];
            if(statedElement.elementState == 0 && statedElement.onCurrentMap) {
                if(collectElement(statedElement.elementId))
                    return;
            }
        }
    }

    Logger::write("No element of id " + to_string(elementTypeId) + " is currently available", LOG_WARNING);
}

bool BasicActionsFrame::collectElement(int elementId) {
    auto interactiveElement = dofusBotParent->mapInfos.interactiveElements[elementId];
    auto statedElement = dofusBotParent->mapInfos.statedElements[elementId];
    
    MovementPath movPath = PathFinding::findPath(&dofusBotParent->mapInfos, dofusBotParent->playedCharacter->cellId, statedElement.elementCellId);

    // if(movPath)
    int lastCellId = movPath.toKeyMovements().back() & 0xFFF;

    int dX = abs(dofusBotParent->mapInfos.cellId_to_XPosition(statedElement.elementCellId) - dofusBotParent->mapInfos.cellId_to_XPosition(lastCellId)); 
    int dY = abs(dofusBotParent->mapInfos.cellId_to_YPosition(statedElement.elementCellId) - dofusBotParent->mapInfos.cellId_to_YPosition(lastCellId)); 

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