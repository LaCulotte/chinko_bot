#include "RoleplayMapManager.h"

bool RoleplayMapManager::loadMapInformations(sp<MapComplementaryInformationsDataMessage> mcidMsg) {
    this->clearAll();
    if(!AbstractMapManager::loadMapInformations(mcidMsg->mapId)) 
        return false;

    for(auto actor : mcidMsg->actors)
        this->addActor(actor);

    // interactiveElements = mcidMsg->interactiveElements;
    for (auto interactiveElement : mcidMsg->interactiveElements) {
        this->interactiveElements[interactiveElement->elementId] = interactiveElement;
    }
    for (auto statedElement : mcidMsg->statedElements) {
        this->statedElements[statedElement.elementId] = statedElement;
    }
    hasAggressiveMonsters = mcidMsg->hasAggressiveMonsters;


    for(MapObstacle obstacle : mcidMsg->obstacles)
        // Le 1 correspond à MapObstacleStateEnum::OBSTACLE_OPEN (sinon 2 qui correspond à MapObstacleStateEnum::OPSTACLE_CLOSED)
        if(obstacle.state != 1 && isInMap(obstacle.obstacleCellId))
            cells[obstacle.obstacleCellId]->isBlockedByObstacle = true;

    return true;
}

void RoleplayMapManager::addActor(const sp<GameContextActorInformations> actorInfos) {
    if(!dynamic_pointer_cast<GameRolePlayActorInformations>(actorInfos)) {
        Logger::write("Adding a non-roleplay actor to a RoleplayMapManager.", LOG_WARNING);
    }
    
    sp<ActorData> actorData;

    switch (actorInfos->getId()) {
    case GameRolePlayCharacterInformations::typeId:
    case GameRolePlayHumanoidInformations::typeId:
        {
            sp<GameRolePlayHumanoidInformations> grphInfos = dynamic_pointer_cast<GameRolePlayHumanoidInformations>(actorInfos);
            sp<RoleplayCharacterData> characterData(new RoleplayCharacterData());
            
            characterData->accountId = grphInfos->accountId;
            characterData->restrictions = grphInfos->humanoidInfo->restrictions;
            characterData->name = grphInfos->name;
            
            actorData = characterData;
            players[actorInfos->contextualId] = characterData;
        }
        break;
    
    case GameRolePlayGroupMonsterInformations::typeId:
        {
            sp<GameRolePlayGroupMonsterInformations> grpgmInfos = dynamic_pointer_cast<GameRolePlayGroupMonsterInformations>(actorInfos);
            sp<RoleplayMonsterGroupData> monsterGroupData(new RoleplayMonsterGroupData());

            monsterGroupData->mainMonster = grpgmInfos->staticInfos->mainCreatureLightInfos;
            for (auto underling : grpgmInfos->staticInfos->underlings) 
                monsterGroupData->underlings.push_back(underling);

            actorData = monsterGroupData;
            monsterGroups[actorInfos->contextualId] = monsterGroupData;
        }
        break;

    case GameRolePlayNpcWithQuestInformations::typeId:
        {
            sp<GameRolePlayNpcWithQuestInformations> grpnwqInfos = dynamic_pointer_cast<GameRolePlayNpcWithQuestInformations>(actorInfos);
            sp<RoleplayNpcWithQuestData> npcWithQuestData(new RoleplayNpcWithQuestData());

            npcWithQuestData->questFlag = grpnwqInfos->questFlag;
            npcWithQuestData->npcId = grpnwqInfos->npcId;

            actorData = npcWithQuestData;
            npcs[actorInfos->contextualId] = npcWithQuestData;
        }
        break;

    case GameRolePlayNpcInformations::typeId:
        {
            sp<GameRolePlayNpcInformations> grpnInfos = dynamic_pointer_cast<GameRolePlayNpcInformations>(actorInfos);
            sp<RoleplayNpcData> npcData(new RoleplayNpcData());

            npcData->npcId = grpnInfos->npcId;

            actorData = npcData;
            npcs[actorInfos->contextualId] = npcData;
        }
        break;

    default:
        actorData = make_shared<ActorData>();
    }

    actorData->contextualId = actorInfos->contextualId;
    actorData->cellId       = actorInfos->disposition->cellId;
    actorData->direction    = actorInfos->disposition->direction;

    switch (actorInfos->getId())
    {
    case GameRolePlayTaxCollectorInformations::typeId:
    case GameRolePlayPrismInformations::typeId:
    case GameRolePlayPortalInformations::typeId:
        actorData->allowMovementThrough = true; 
        break;
    }

    allActors[actorData->contextualId] = actorData;
}

void RoleplayMapManager::removeActor(double actorId) {
    AbstractMapManager::removeActor(actorId);
    
    players.erase(actorId);
    monsterGroups.erase(actorId);
    npcs.erase(actorId);
}

sp<RoleplayCharacterData> RoleplayMapManager::getPlayer(double playerId) {
    auto playerIt = players.find(playerId);
    if(playerIt != players.end())
        if(!playerIt->second.expired())
            return playerIt->second.lock();
        else 
            players.erase(playerIt);

    return nullptr;
}

sp<RoleplayNpcData> RoleplayMapManager::getNpc(double npcId) {
    auto npcIt = npcs.find(npcId);
    if(npcIt != npcs.end())
        if(!npcIt->second.expired())
            return npcIt->second.lock();
        else 
            npcs.erase(npcIt);

    return nullptr;
}

sp<RoleplayMonsterGroupData> RoleplayMapManager::getMonsterGroup(double monsterGroupId) {
    auto monsterGroupIt = monsterGroups.find(monsterGroupId);
    if(monsterGroupIt != monsterGroups.end())
        if(!monsterGroupIt->second.expired())
            return monsterGroupIt->second.lock();
        else 
            monsterGroups.erase(monsterGroupIt);

    return nullptr;
}

void RoleplayMapManager::updateInteractiveElement(sp<InteractiveElement> interactive) {
    auto interactiveIt = interactiveElements.find(interactive->elementId);
    if(interactiveIt != interactiveElements.end()) {
        interactiveIt->second->enabledSkills = interactive->enabledSkills;
        interactiveIt->second->disabledSkills = interactive->disabledSkills;
        interactiveIt->second->onCurrentMap = interactive->onCurrentMap;
        interactiveIt->second->elementTypeId = interactive->elementTypeId;
    } else {
        interactiveElements[interactive->elementId] = interactive;
    }
}

void RoleplayMapManager::updateInteractiveElement(InteractiveElement interactive) {
    auto interactiveIt = interactiveElements.find(interactive.elementId);
    if(interactiveIt != interactiveElements.end()) {
        interactiveIt->second->enabledSkills = interactive.enabledSkills;
        interactiveIt->second->disabledSkills = interactive.disabledSkills;
        interactiveIt->second->onCurrentMap = interactive.onCurrentMap;
        interactiveIt->second->elementTypeId = interactive.elementTypeId;
    } else {
        interactiveElements[interactive.elementId] = make_shared<InteractiveElement>(interactive);
    }
}

void RoleplayMapManager::updateStatedElement(StatedElement stated) {
    auto statedIt = statedElements.find(stated.elementId);
    if(statedIt != statedElements.end()) {
        statedIt->second.elementState = stated.elementState;
        statedIt->second.onCurrentMap = stated.onCurrentMap;
        statedIt->second.elementCellId = stated.elementCellId;
    } else {
        statedElements[stated.elementId] = stated;
    }
}

void RoleplayMapManager::clearAll() {
    AbstractMapManager::clearAll();

    players.clear();
    monsterGroups.clear();
    npcs.clear();

    interactiveElements.clear();
    statedElements.clear();
}