#include "RoleplayMapManager.h"

bool RoleplayMapManager::loadMapInformations(sp<MapComplementaryInformationsDataMessage> mcidMsg) {
    this->clearAll();
    // Loads abstract map infos
    if(!AbstractMapManager::loadMapInformations(mcidMsg->mapId)) 
        return false;

    // Loads actors
    for(auto actor : mcidMsg->actors)
        this->addActor(actor);

    // Loads interactive elements
    for (auto interactiveElement : mcidMsg->interactiveElements) {
        this->interactiveElements[interactiveElement->elementId] = interactiveElement;
    }
    // Loads stated elements
    for (auto statedElement : mcidMsg->statedElements) {
        this->statedElements[statedElement.elementId] = statedElement;
    }
    hasAggressiveMonsters = mcidMsg->hasAggressiveMonsters;

    // Loads obstacles
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

    // Builds actor instance depending on the type of actor informations
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

    // Sets informations
    actorData->contextualId = actorInfos->contextualId;
    actorData->cellId       = actorInfos->disposition->cellId;
    actorData->direction    = actorInfos->disposition->direction;

    // Sets allowMovementThrough depending on the type of actor
    switch (actorInfos->getId())
    {
    case GameRolePlayTaxCollectorInformations::typeId:
    case GameRolePlayPrismInformations::typeId:
    case GameRolePlayPortalInformations::typeId:
        actorData->allowMovementThrough = true; 
        break;
    }

    // Adds actor to map
    allActors[actorData->contextualId] = actorData;
}

void RoleplayMapManager::removeActor(double actorId) {
    AbstractMapManager::removeActor(actorId);
    
    // Erase actor from all maps
    players.erase(actorId);
    monsterGroups.erase(actorId);
    npcs.erase(actorId);
}

sp<RoleplayCharacterData> RoleplayMapManager::getPlayer(double playerId) {
    // Gets player
    auto playerIt = players.find(playerId);
    if(playerIt != players.end())
        if(!playerIt->second.expired())
            return playerIt->second.lock();
        else 
            // Removes the player from the map if it is not valid anymore
            players.erase(playerIt);

    return nullptr;
}

sp<RoleplayNpcData> RoleplayMapManager::getNpc(double npcId) {
    // Gets NPC
    auto npcIt = npcs.find(npcId);
    if(npcIt != npcs.end())
        if(!npcIt->second.expired())
            // Removes the NPC from the map if it is not valid anymore
            return npcIt->second.lock();
        else 
            npcs.erase(npcIt);

    return nullptr;
}

sp<RoleplayMonsterGroupData> RoleplayMapManager::getMonsterGroup(double monsterGroupId) {
    // Gets monster group
    auto monsterGroupIt = monsterGroups.find(monsterGroupId);
    if(monsterGroupIt != monsterGroups.end())
        if(!monsterGroupIt->second.expired())
            return monsterGroupIt->second.lock();
        else 
            // Removes the monster group from the map if it is not valid anymore
            monsterGroups.erase(monsterGroupIt);

    return nullptr;
}

void RoleplayMapManager::updateInteractiveElement(sp<InteractiveElement> interactive) {
    // Gets interactive element
    auto interactiveIt = interactiveElements.find(interactive->elementId);
    if(interactiveIt != interactiveElements.end()) {
        // If it already exists, update
        interactiveIt->second->enabledSkills = interactive->enabledSkills;
        interactiveIt->second->disabledSkills = interactive->disabledSkills;
        interactiveIt->second->onCurrentMap = interactive->onCurrentMap;
        interactiveIt->second->elementTypeId = interactive->elementTypeId;
    } else {
        // Else, adds it
        interactiveElements[interactive->elementId] = interactive;
    }
}

void RoleplayMapManager::updateInteractiveElement(InteractiveElement interactive) {
    // Gets interactive element
    auto interactiveIt = interactiveElements.find(interactive.elementId);
    if(interactiveIt != interactiveElements.end()) {
        // If it already exists, update
        interactiveIt->second->enabledSkills = interactive.enabledSkills;
        interactiveIt->second->disabledSkills = interactive.disabledSkills;
        interactiveIt->second->onCurrentMap = interactive.onCurrentMap;
        interactiveIt->second->elementTypeId = interactive.elementTypeId;
    } else {
        interactiveElements[interactive.elementId] = make_shared<InteractiveElement>(interactive);
    }
}

void RoleplayMapManager::updateStatedElement(StatedElement stated) {
    // Gets stated element
    auto statedIt = statedElements.find(stated.elementId);
    if(statedIt != statedElements.end()) {
        // If it already exists, update
        statedIt->second.elementState = stated.elementState;
        statedIt->second.onCurrentMap = stated.onCurrentMap;
        statedIt->second.elementCellId = stated.elementCellId;
    } else {
        // Else, adds it
        statedElements[stated.elementId] = stated;
    }
}

void RoleplayMapManager::clearAll() {
    AbstractMapManager::clearAll();

    // Clears every maps
    players.clear();
    monsterGroups.clear();
    npcs.clear();

    interactiveElements.clear();
    statedElements.clear();
}