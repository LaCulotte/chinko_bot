#include "CurrentMapManager.h"

#include "math.h"
#include "GameRolePlayTaxCollectorInformations.h"
#include "GameRolePlayPortalInformations.h"
#include "GameRolePlayPrismInformations.h"

#define TOLERENCE_ELEVATION 11
#define sign(x) ((x) > 0 ) - ((x) < 0)

bool CurrentMapManager::loadMapInformations(sp<MapComplementaryInformationsDataMessage> mcidMsg) {
    clearAll();

    for(auto actor : mcidMsg->actors)
        addActor(actor);

    // interactiveElements = mcidMsg->interactiveElements;
    for (auto interactiveElement : mcidMsg->interactiveElements) {
        this->interactiveElements[interactiveElement->elementId] = interactiveElement;
    }
    for (auto statedElement : mcidMsg->statedElements) {
        this->statedElements[statedElement.elementId] = statedElement;
    }
    mapId = mcidMsg->mapId;
    hasAggressiveMonsters = mcidMsg->hasAggressiveMonsters;

    if(!this->loadMapCellsInformations()) 
        return false;

    for(MapObstacle obstacle : mcidMsg->obstacles)
        // Le 1 correspond à MapObstacleStateEnum::OBSTACLE_OPEN (sinon 2 qui correspond à MapObstacleStateEnum::OPSTACLE_CLOSED)
        if(obstacle.state != 1 && isInMap(obstacle.obstacleCellId))
            cells[obstacle.obstacleCellId]->isBlockedByObstacle = true;

    return true;
}

void CurrentMapManager::addActor(const sp<GameRolePlayActorInformations> actorInfos) {
    sp<ActorData> actorData;

    switch (actorInfos->getId()) {
    case GameRolePlayCharacterInformations::typeId:
    case GameRolePlayHumanoidInformations::typeId:
        {
            sp<GameRolePlayHumanoidInformations> grphInfos = dynamic_pointer_cast<GameRolePlayHumanoidInformations>(actorInfos);
            sp<CharacterData> characterData(new CharacterData());
            
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
            sp<MonsterGroupData> monsterGroupData(new MonsterGroupData());

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
            sp<NpcWithQuestData> npcWithQuestData(new NpcWithQuestData());

            npcWithQuestData->questFlag = grpnwqInfos->questFlag;
            npcWithQuestData->npcId = grpnwqInfos->npcId;

            actorData = npcWithQuestData;
            npcs[actorInfos->contextualId] = npcWithQuestData;
        }
        break;

    case GameRolePlayNpcInformations::typeId:
        {
            sp<GameRolePlayNpcInformations> grpnInfos = dynamic_pointer_cast<GameRolePlayNpcInformations>(actorInfos);
            sp<NpcData> npcData(new NpcData());

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

bool CurrentMapManager::loadMapInformations(int mapId) {
    clearAll();
    
    this->mapId = mapId;
    
    return this->loadMapCellsInformations();
}

bool CurrentMapManager::loadMapCellsInformations() {
    ostringstream filename_strstream;
    filename_strstream.precision(0);
    filename_strstream << mapsFolder << "/" << fixed << mapId << ".json";

    ifstream mapFile_stream(filename_strstream.str(), ifstream::binary);

    if(!mapFile_stream) {
        Logger::write("Cannot open the map information file of mapId : " + to_string(mapId) + ".", LOG_ERROR);
        return false;
    }

    Json::Value mapFile_json;
    Json::Reader mapFile_reader;

    bool couldRead = mapFile_reader.parse(mapFile_stream, mapFile_json);

    if(!couldRead) {
        Logger::write("Cannot read the map information file of mapId : " + to_string(mapId) + "; it is not a correct json file.", LOG_ERROR);
        return false;
    }

    if(!mapFile_json["cells"]) {
        Logger::write("The map information file of mapId : " + to_string(mapId) + " is not a valid information file : does not contain \"cells\"", LOG_ERROR);
        return false;
    }

    cells.clear();
    for(auto cell_json : mapFile_json["cells"]) {
        sp<Cell> cell(new Cell());
        cell->mov = cell_json["mov"].asBool();
        cell->floor = cell_json["floor"].asInt();
        cell->moveZone = cell_json["moveZone"].asInt();
        cell->speed = cell_json["speed"].asInt();
        cell->mapChangeData = cell_json["mapChangeData"].asInt();
        cell->linkedZone = cell_json["_linkedZone"].asInt();

        if((cell->mapChangeData & 0x01) != 0)
            rightChangeMapCellsId.push_back(cells.size());
        if((cell->mapChangeData & 0x10) != 0)
            leftChangeMapCellsId.push_back(cells.size());
        if((cell->mapChangeData & 0x40) != 0)
            upChangeMapCellsId.push_back(cells.size());
        if((cell->mapChangeData & 0x04) != 0)
            downChangeMapCellsId.push_back(cells.size());
        
        cells.push_back(cell);
    }

    rightMapId = mapFile_json["rightNeighbourId"].asDouble();
    downMapId = mapFile_json["bottomNeighbourId"].asDouble();
    leftMapId = mapFile_json["leftNeighbourId"].asDouble();
    upMapId = mapFile_json["topNeighbourId"].asDouble();

    return true;
}

void CurrentMapManager::clearAll() {
    allActors.clear();
    players.clear();
    monsterGroups.clear();
    npcs.clear();

    interactiveElements.clear();
    statedElements.clear();

    cells.clear();
    upChangeMapCellsId.clear();
    rightChangeMapCellsId.clear();
    downChangeMapCellsId.clear();
    leftChangeMapCellsId.clear();

    mapId = 0;
    subAreaId = 0;
    hasAggressiveMonsters = false;
}

int CurrentMapManager::cellId_to_XPosition(int cellId) {
    return (cellId % MAP_WIDTH) + ceil(((float) (cellId / MAP_WIDTH)) / 2);
}

int CurrentMapManager::cellId_to_YPosition(int cellId) {
    return (cellId % MAP_WIDTH) - floor(((float) (cellId / MAP_WIDTH)) / 2);
}

int CurrentMapManager::position_to_cellId(int x, int y) {
    return (x - y) * MAP_WIDTH + y + (x - y)/2;
}

int CurrentMapManager::getManhattanDistance(int cellId1, int cellId2) {
    int x1 = cellId_to_XPosition(cellId1);
    int y1 = cellId_to_YPosition(cellId1);
    int x2 = cellId_to_XPosition(cellId2);
    int y2 = cellId_to_YPosition(cellId2);

    return abs(x2 - x1) + abs(y2 - y1);
}

float CurrentMapManager::getEuclidianDistance(int cellId1, int cellId2) {
    int x1 = cellId_to_XPosition(cellId1);
    int y1 = cellId_to_YPosition(cellId1);
    int x2 = cellId_to_XPosition(cellId2);
    int y2 = cellId_to_YPosition(cellId2);

    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// TODO : support allowThroughEntities = false -> scripts/com/ankamagames/jerakine/pathFinding/PathFinding.as
bool CurrentMapManager::canMove(int cellId, int previousCellId, bool avoidObstacles, bool allowThroughEntities) {
    if(!isInMap(cellId))
        return false;

    // TODO : slightly different when in battle; see scripts/com/ankamagames/atouin/utils/DataMapProvider.as:138 
    bool mov = cells[cellId]->mov && !cells[cellId]->isBlockedByObstacle; 

    // Peut être alléger en ajoutant hasObstacleOnTop comme attribut de Cell
    // for (MapObstacle obstacle : obstacles) {
    //     // Le 1 correspond à MapObstacleStateEnum.OBSTACLE_OPEN -> à implémenter
    //     if(obstacle.obstacleCellId == cellId && obstacle.state != 1)
    //         mov = false;
    // }

    if(mov && previousCellId != -1 && previousCellId != cellId) {
        sp<Cell> cell = cells[cellId];
        sp<Cell> previousCell = cells[previousCellId];

        int floorDiff = abs(abs(cell->floor) - abs(previousCell->floor));

        if (previousCell->moveZone != cell->moveZone && floorDiff > 0 || previousCell->moveZone == cell->moveZone && cell->moveZone == 0 && floorDiff > TOLERENCE_ELEVATION)
            mov = false;
    }

    // TODO : if(!allowTroughEntities)

    return mov;
}

bool CurrentMapManager::isThereBlockingEntityOn(int cellId) {
    for(auto actorIt : allActors) {
        sp<ActorData> actor = actorIt.second;
        if(actor->cellId == cellId && !actor->allowMovementThrough)
            return true;
    }

    return false;
}

bool CurrentMapManager::isChangeZone(int cellId1, int cellId2) {
    if(!isInMap(cellId1) || !isInMap(cellId2))
        return true;

    int floorDiff = abs(abs(cells[cellId1]->floor) - abs(cells[cellId2]->floor));

    return cells[cellId1]->moveZone !=  cells[cellId2]->moveZone && floorDiff > 0; 
}

int CurrentMapManager::getLookDirection(int fromCellId, int toCellId) {
    return getLookDirection(cellId_to_XPosition(fromCellId), cellId_to_YPosition(fromCellId), cellId_to_XPosition(toCellId), cellId_to_YPosition(toCellId));
}

int CurrentMapManager::getLookDirection(int fromCellX, int fromCellY, int toCellX, int toCellY) {
    int dX = sign(toCellX - fromCellX);
    int dY = sign(toCellY - fromCellY);

    int dir = 3 - (2 * dX) - dX * dY;

    if(dX == 0 && dY == 1)
        dir += 4;

    return dir;
}

sp<ActorData> CurrentMapManager::getActor(double actorId) {
    // for (auto actorIt : allActors) {
    //     sp<ActorData> actor = actorIt.second;
    //     if(actor->contextualId == actorId)
    //         return actor;
    // }

    auto actorIt = allActors.find(actorId);
    if(actorIt != allActors.end())
        return actorIt->second;

    return nullptr;
}

void CurrentMapManager::removeActor(double actorId) {
    allActors.erase(actorId);
    players.erase(actorId);
    monsterGroups.erase(actorId);
    npcs.erase(actorId);
}

sp<CharacterData> CurrentMapManager::getPlayer(double playerId) {
    auto playerIt = players.find(playerId);
    if(playerIt != players.end())
        return playerIt->second.lock();

    return nullptr;
}

sp<NpcData> CurrentMapManager::getNpc(double npcId) {
    auto npcIt = npcs.find(npcId);
    if(npcIt != npcs.end())
        return npcIt->second.lock();

    return nullptr;
}

sp<MonsterGroupData> CurrentMapManager::getMonsterGroup(double monsterGroupId) {
    auto monsterGroupIt = monsterGroups.find(monsterGroupId);
    if(monsterGroupIt != monsterGroups.end())
        return monsterGroupIt->second.lock();

    return nullptr;
}

bool CurrentMapManager::updateActorPosition(double actorId, int newCellId) {
    // for (auto actorIt : allActors) {
    //     sp<ActorData> actor = actorIt.second;
    //     if(actor->contextualId == actorId)
    //         actor->cellId = newCellId;
    // }

    auto actorIt = allActors.find(actorId);
    if(actorIt != allActors.end()) {
        actorIt->second->cellId = newCellId;
        return true;
    }

    return false;
}

void CurrentMapManager::updateInteractiveElement(sp<InteractiveElement> interactive) {
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

void CurrentMapManager::updateInteractiveElement(InteractiveElement interactive) {
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

void CurrentMapManager::updateStatedElement(StatedElement stated) {
    auto statedIt = statedElements.find(stated.elementId);
    if(statedIt != statedElements.end()) {
        statedIt->second.elementState = stated.elementState;
        statedIt->second.onCurrentMap = stated.onCurrentMap;
        statedIt->second.elementCellId = stated.elementCellId;
    } else {
        statedElements[stated.elementId] = stated;
    }
}

// int CurrentMapManager::getClosestCellIdFromVector(int cellId, vector<int> cells) {
//     if(cells.size() > 0)
//         return -1;
    
//     int minDistCellId = -1;
//     int minDist = 99999;

//     for(int destCellId : cells) {
//         int destCellDist = getManhattanDistance(cellId, destCellId);
//         if(destCellDist < minDist) {
//             minDist = destCellDist;
//             minDistCellId = destCellId;
//         }
//     }

//     return minDistCellId;
// }

bool CurrentMapManager::isCoordsInMap(int x, int y) {
    if(y >= -x && y <= x && y <= MAP_WIDTH + 13 - x)
        return y >= x - (MAP_HEIGHT - (-19));

    return false;
}