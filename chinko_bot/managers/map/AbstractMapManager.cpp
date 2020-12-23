#include "AbstractMapManager.h"

#include "math.h"
#include "As3_Math.h"
#include "GameRolePlayTaxCollectorInformations.h"
#include "GameRolePlayPortalInformations.h"
#include "GameRolePlayPrismInformations.h"

#define TOLERENCE_ELEVATION 11
#define sign(x) ((x) > 0 ) - ((x) < 0)

// bool AbstractMapManager::loadMapInformations(sp<MapComplementaryInformationsDataMessage> mcidMsg) {
//     clearAll();

//     for(auto actor : mcidMsg->actors)
//         addActor(actor);

//     // interactiveElements = mcidMsg->interactiveElements;
//     for (auto interactiveElement : mcidMsg->interactiveElements) {
//         this->interactiveElements[interactiveElement->elementId] = interactiveElement;
//     }
//     for (auto statedElement : mcidMsg->statedElements) {
//         this->statedElements[statedElement.elementId] = statedElement;
//     }
//     mapId = mcidMsg->mapId;
//     hasAggressiveMonsters = mcidMsg->hasAggressiveMonsters;

//     if(!this->loadMapCellsInformations()) 
//         return false;

//     for(MapObstacle obstacle : mcidMsg->obstacles)
//         // Le 1 correspond à MapObstacleStateEnum::OBSTACLE_OPEN (sinon 2 qui correspond à MapObstacleStateEnum::OPSTACLE_CLOSED)
//         if(obstacle.state != 1 && isInMap(obstacle.obstacleCellId))
//             cells[obstacle.obstacleCellId]->isBlockedByObstacle = true;

//     return true;
// }

// void AbstractMapManager::addActor(const sp<GameRolePlayActorInformations> actorInfos) {
//     sp<ActorData> actorData;

//     switch (actorInfos->getId()) {
//     case GameRolePlayCharacterInformations::typeId:
//     case GameRolePlayHumanoidInformations::typeId:
//         {
//             sp<GameRolePlayHumanoidInformations> grphInfos = dynamic_pointer_cast<GameRolePlayHumanoidInformations>(actorInfos);
//             sp<RoleplayCharacterData> characterData(new RoleplayCharacterData());
            
//             characterData->accountId = grphInfos->accountId;
//             characterData->restrictions = grphInfos->humanoidInfo->restrictions;
//             characterData->name = grphInfos->name;
            
//             actorData = characterData;
//             players[actorInfos->contextualId] = characterData;
//         }
//         break;
    
//     case GameRolePlayGroupMonsterInformations::typeId:
//         {
//             sp<GameRolePlayGroupMonsterInformations> grpgmInfos = dynamic_pointer_cast<GameRolePlayGroupMonsterInformations>(actorInfos);
//             sp<RoleplayMonsterGroupData> monsterGroupData(new RoleplayMonsterGroupData());

//             monsterGroupData->mainMonster = grpgmInfos->staticInfos->mainCreatureLightInfos;
//             for (auto underling : grpgmInfos->staticInfos->underlings) 
//                 monsterGroupData->underlings.push_back(underling);

//             actorData = monsterGroupData;
//             monsterGroups[actorInfos->contextualId] = monsterGroupData;
//         }
//         break;

//     case GameRolePlayNpcWithQuestInformations::typeId:
//         {
//             sp<GameRolePlayNpcWithQuestInformations> grpnwqInfos = dynamic_pointer_cast<GameRolePlayNpcWithQuestInformations>(actorInfos);
//             sp<RoleplayNpcWithQuestData> npcWithQuestData(new RoleplayNpcWithQuestData());

//             npcWithQuestData->questFlag = grpnwqInfos->questFlag;
//             npcWithQuestData->npcId = grpnwqInfos->npcId;

//             actorData = npcWithQuestData;
//             npcs[actorInfos->contextualId] = npcWithQuestData;
//         }
//         break;

//     case GameRolePlayNpcInformations::typeId:
//         {
//             sp<GameRolePlayNpcInformations> grpnInfos = dynamic_pointer_cast<GameRolePlayNpcInformations>(actorInfos);
//             sp<RoleplayNpcData> npcData(new RoleplayNpcData());

//             npcData->npcId = grpnInfos->npcId;

//             actorData = npcData;
//             npcs[actorInfos->contextualId] = npcData;
//         }
//         break;

//     default:
//         actorData = make_shared<ActorData>();
//     }

//     actorData->contextualId = actorInfos->contextualId;
//     actorData->cellId       = actorInfos->disposition->cellId;
//     actorData->direction    = actorInfos->disposition->direction;

//     switch (actorInfos->getId())
//     {
//     case GameRolePlayTaxCollectorInformations::typeId:
//     case GameRolePlayPrismInformations::typeId:
//     case GameRolePlayPortalInformations::typeId:
//         actorData->allowMovementThrough = true; 
//         break;
//     }

//     allActors[actorData->contextualId] = actorData;
// }

bool AbstractMapManager::loadMapInformations(int mapId) {
    this->clearAll();
    
    this->mapId = mapId;
    this->cellsLoaded = false;
    
    return this->loadMapCellsInformations();
}

bool AbstractMapManager::loadMapCellsInformations() {
    ostringstream filename_strstream;
    filename_strstream.precision(0); 
    filename_strstream << mapsFolder << "/" << fixed << mapId << ".json";

    ifstream mapFile_stream(filename_strstream.str(), ifstream::binary);

    if(!mapFile_stream) {
        Logger::write("Cannot open the map information file of mapId : " + to_string(mapId) + ".", LOG_ERROR);
        return false;
    }

    Json::Value mapFile_json;
    // Json::Reader mapFile_reader;
    Json::CharReaderBuilder builder;

    string error_str;
    bool couldRead = Json::parseFromStream(builder, mapFile_stream, &mapFile_json, &error_str);

    if(!couldRead) {
        Logger::write("Cannot read the map information file of mapId : " + to_string(mapId) + "; it is not a correct json file. Error : " + error_str, LOG_ERROR);
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
        cell->los = cell_json["los"].asBool();
        cell->nonWalkableDuringFight = cell_json["nonWalkableDuringFight"].asBool();
        cell->nonWalkableDuringRP = cell_json["nonWalkableDuringRP"].asBool();
        cell->farmCell = cell_json["farmCell"].asBool();
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

    cellsLoaded = true;

    return true;
}

void AbstractMapManager::clearAll() {
    allActors.clear();

    cells.clear();
    upChangeMapCellsId.clear();
    rightChangeMapCellsId.clear();
    downChangeMapCellsId.clear();
    leftChangeMapCellsId.clear();

    mapId = 0;
    subAreaId = 0;
    hasAggressiveMonsters = false;
}

int AbstractMapManager::cellId_to_XPosition(int cellId) {
    return (cellId % MAP_WIDTH) + ceil(((float) (cellId / MAP_WIDTH)) / 2);
}

int AbstractMapManager::cellId_to_YPosition(int cellId) {
    return (cellId % MAP_WIDTH) - floor(((float) (cellId / MAP_WIDTH)) / 2);
}

int AbstractMapManager::position_to_cellId(int x, int y) {
    return (x - y) * MAP_WIDTH + y + (x - y)/2;
}

int AbstractMapManager::getManhattanDistance(int cellId1, int cellId2) {
    int x1 = cellId_to_XPosition(cellId1);
    int y1 = cellId_to_YPosition(cellId1);
    int x2 = cellId_to_XPosition(cellId2);
    int y2 = cellId_to_YPosition(cellId2);

    return abs(x2 - x1) + abs(y2 - y1);
}

float AbstractMapManager::getEuclidianDistance(int cellId1, int cellId2) {
    int x1 = cellId_to_XPosition(cellId1);
    int y1 = cellId_to_YPosition(cellId1);
    int x2 = cellId_to_XPosition(cellId2);
    int y2 = cellId_to_YPosition(cellId2);

    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

bool AbstractMapManager::canMove(int cellId, int previousCellId, int endCellId, bool avoidObstacles, bool allowThroughEntities) {
    if(!isInMap(cellId))
        return false;

    bool mov = cells[cellId]->mov && !cells[cellId]->isBlockedByObstacle && ((this->isFight() && !cells[cellId]->nonWalkableDuringFight) || (!this->isFight() && !cells[cellId]->nonWalkableDuringRP)); 
    
    if(mov && previousCellId != -1 && previousCellId != cellId) {
        sp<Cell> cell = cells[cellId];
        sp<Cell> previousCell = cells[previousCellId];

        int floorDiff = abs(abs(cell->floor) - abs(previousCell->floor));

        if (previousCell->moveZone != cell->moveZone && floorDiff > 0 || previousCell->moveZone == cell->moveZone && cell->moveZone == 0 && floorDiff > TOLERENCE_ELEVATION)
            mov = false;
    }

    if(!allowThroughEntities) {
        for (auto actorIt : allActors) {
            if(actorIt.second->cellId == cellId && !(endCellId != cellId && actorIt.second->canWalkTo) && !actorIt.second->canWalkThrough) {
                return false;
            }
        }

        if(avoidObstacles && cells[cellId]->nbMarks != 0 && cellId != endCellId)
            return false;
    }

    return mov;
}

/*  
    cell1&2 are arrays of 2 elements : cellId and distance to referencePosition
    returns true if cell1's distance is lower than cell2's distance
*/
bool AbstractMapManager::sortCellDist(int* cell1, int* cell2) {
    return (cell1[1] < cell2[1]);
}

vector<int> AbstractMapManager::getLine(int cell1, int cell2) {
    vector<int> ret;

    float dist = this->getEuclidianDistance(cell1, cell2);

    int x1 = this->cellId_to_XPosition(cell1);
    int y1 = this->cellId_to_YPosition(cell1);
    int x2 = this->cellId_to_XPosition(cell2);
    int y2 = this->cellId_to_YPosition(cell2);

    float x_step = dist / abs(x2 - x1);
    float y_step = dist / abs(y2 - y1);
    float x_agent = x_step / 2;
    float y_agent = y_step / 2;

    int x_sign = (x2 < x1)?-1:1;
    int y_sign = (y2 < y1)?-1:1;

    while(x1 != x2 || y1 != y2) {
        if(abs(x_agent - y_agent) < 0.0001) {
            x_agent += x_step;
            y_agent += y_step;

            x1 += x_sign;
            y1 += y_sign;
        } else if(x_agent < y_agent) {
            x_agent += x_step;
            x1 += x_sign;
        } else {
            y_agent += y_step;
            y1 += y_sign;

        }

        ret.push_back(this->position_to_cellId(x1, y1));
    }

    return ret;
}

bool AbstractMapManager::isThereLos(int destCellId, int referencePosition) {
    vector<int> line = this->getLine(referencePosition, destCellId);

    int referenceX = this->cellId_to_XPosition(referencePosition);
    int referenceY = this->cellId_to_YPosition(referencePosition);

    if(line.size() == 0) {
        return true;
    } else {
        bool los = true;
        for(int i = 0; i < line.size(); i++) {
            int cellId = line[i];
            int cellX = this->cellId_to_XPosition(cellId);
            int cellY = this->cellId_to_YPosition(cellId);

            if(isInMap(cellId)) {
                if(i > 0 && this->isThereSeeBlockingEntityOn(line[i - 1], true)) {
                    return false;
                } else {
                    los = los && !cells[cellId]->isBlockedByObstacle && cells[cellId]->los;
                }
            }
        }

        return los;
    }
}

vector<int> AbstractMapManager::getLosFromCells(vector<int> range, int referencePosition) {
    vector<int*> orderedCells;
    unordered_map<int, bool> testedCells;
    vector<int> result;

    int referenceX = this->cellId_to_XPosition(referencePosition);
    int referenceY = this->cellId_to_YPosition(referencePosition);

    for(int cell : range) {
        // int cellAndDist[2] = {cell, this->getManhattanDistance(cell, referencePosition)};
        int* cellAndDist = (int *) malloc(2 * sizeof(int));
        cellAndDist[0] = cell;
        cellAndDist[1] = this->getManhattanDistance(cell, referencePosition);
        orderedCells.push_back(cellAndDist);
    }

    sort(orderedCells.begin(), orderedCells.end(), sortCellDist);

    for(int* cellAndDist : orderedCells) {
        int cellId = cellAndDist[0];
        int cellX = this->cellId_to_XPosition(cellId);
        int cellY = this->cellId_to_YPosition(cellId);

        if(testedCells.find(cellId) == testedCells.end() || referenceX + referenceY == cellX + cellY || referenceX - referenceY == cellX - cellY) {

            vector<int> line = this->getLine(referencePosition, cellId);

            int referenceX = this->cellId_to_XPosition(referencePosition);
            int referenceY = this->cellId_to_YPosition(referencePosition);

            if(line.size() == 0) {
                // return true
                // result.push_back(cellId);
                testedCells[cellId] = true;
            } else {
                bool los = true;

                for(int i = 0; i < line.size(); i++) {
                    int lineCellId = line[i];
                    int lineCellX = this->cellId_to_XPosition(lineCellId);
                    int lineCellY = this->cellId_to_YPosition(lineCellId);

                    // if(isCoordsInMap(lineCellX, lineCellY)) {
                    if(isInMap(lineCellId)) {
                        if(i > 0 && this->isThereSeeBlockingEntityOn(line[i - 1], true)) {
                            los = false;
                            break;
                        } else if(lineCellX + lineCellY == referenceX + referenceY || lineCellX - lineCellY == referenceX - referenceY) {
                            los = los && !cells[lineCellId]->isBlockedByObstacle && cells[lineCellId]->los;
                        } else if(testedCells.find(lineCellId) == testedCells.end()) {
                            los = los && !cells[lineCellId]->isBlockedByObstacle && cells[lineCellId]->los;
                        } else {
                            // los = los && !cells[lineCellId]->isBlockedByObstacle && cells[lineCellId]->los;
                            los = los && testedCells.find(lineCellId)->second;
                        }
                    }
                }

                testedCells[cellId] = los;
            }
        }
    }

    for(auto testedCell : testedCells) {
        if(testedCell.second) 
            result.push_back(testedCell.first);
    }

    return result;
}

bool AbstractMapManager::isThereBlockingEntityOn(int cellId, bool allowThroughEntities) {
    for(auto actorIt : allActors) {
        sp<ActorData> actor = actorIt.second;
        if(actor->cellId == cellId && (!allowThroughEntities || !actor->allowMovementThrough))
            return true;
    }

    return false;
}

bool AbstractMapManager::isThereSeeBlockingEntityOn(int cellId, bool allowThroughEntities) {
    for(auto actorIt : allActors) {
        sp<ActorData> actor = actorIt.second;
        if(actor->cellId == cellId && (!allowThroughEntities || !actor->canSeeThrough))
            return true;
    }

    return false;
}

bool AbstractMapManager::isChangeZone(int cellId1, int cellId2) {
    if(!isInMap(cellId1) || !isInMap(cellId2))
        return true;

    int floorDiff = abs(abs(cells[cellId1]->floor) - abs(cells[cellId2]->floor));

    return cells[cellId1]->moveZone !=  cells[cellId2]->moveZone && floorDiff > 0; 
}

int AbstractMapManager::getLookDirection(int fromCellId, int toCellId) {
    return getLookDirection(cellId_to_XPosition(fromCellId), cellId_to_YPosition(fromCellId), cellId_to_XPosition(toCellId), cellId_to_YPosition(toCellId));
}

int AbstractMapManager::getLookDirection(int fromCellX, int fromCellY, int toCellX, int toCellY) {
    int dX = sign(toCellX - fromCellX);
    int dY = sign(toCellY - fromCellY);

    int dir = 3 - (2 * dX) - dX * dY;

    if(dX == 0 && dY == 1)
        dir += 4;

    return dir;
}

int AbstractMapManager::getAdvancedOrientation(int fromCellX, int fromCellY, int toCellX, int toCellY, bool fourDir) {
    float xDiff = toCellX - fromCellX;
    float yDiff = fromCellY - toCellY;

    float angle = acos(xDiff / sqrt(pow(xDiff, 2) + pow(yDiff, 2))) * 180 / M_PI * (toCellY > fromCellY ? -1:1);
    int retAngle = 0;
    if(fourDir) {
        retAngle = as3_round(angle / 90) * 2 + 1;
    } else {
        retAngle = as3_round(angle / 45) + 1;
    }
    if(retAngle < 0)
        retAngle += 8;

    return retAngle;
} 

int AbstractMapManager::getAdvancedOrientation(int fromCellId, int toCellId, bool fourDir) {
    return getAdvancedOrientation(cellId_to_XPosition(fromCellId), cellId_to_YPosition(fromCellId), cellId_to_XPosition(toCellId), cellId_to_YPosition(toCellId), fourDir);
}

int AbstractMapManager::getNearestCellInDirection(int srcCellId, int dir) {
    int cellX = cellId_to_XPosition(srcCellId);
    int cellY = cellId_to_YPosition(srcCellId);
    switch(dir) {
    case 0:
        cellX++;
        cellY++;
        break;
    case 1:
        cellX++;
        break;        
    case 2:
        cellX++;
        cellY--;
        break;
    case 3:
        cellY--;
        break;
    case 4:
        cellX--;
        cellY--;
        break;
    case 5:
        cellX--;
        break;
    case 6:
        cellX--;
        cellY++;
        break;  
    case 7:
        cellY++;
        break;  
    default:
        Logger::write("Cannot get nearest cell in direction : direction must be between 0 and 7; Current direction : " + to_string(dir));
        return -1;
    }

    if(this->isCoordsInMap(cellX, cellY))
        return position_to_cellId(cellX, cellY);

    return -1;
}

int AbstractMapManager::getNearestFreeCellInDirection(int srcCellId, int dir, bool allowItself, bool allowThroughEntity, bool ignoreSpeed, sp<vector<int>> forbiddenCells) {
    if(!forbiddenCells)
        forbiddenCells = make_shared<vector<int>>();

    int nearCells[8];
    int weights[8];

    for(int i = 0; i < 8; i++) {
        int mpId = getNearestCellInDirection(srcCellId, i);
        sp<Cell> mp = getCell(mpId);

        nearCells[i] = mpId;
        if(mp) {
            if(find(forbiddenCells->begin(), forbiddenCells->end(), mpId) == forbiddenCells->end()) {
                if(this->canMove(mpId, srcCellId, -1, true, allowThroughEntity)) {
                    weights[i] = getOrientationDist(i, dir) + (!ignoreSpeed ?(mp->speed >= 0?5-mp->speed :11+abs(mp->speed)) :0);
                } else {
                    forbiddenCells->push_back(mpId);
                    weights[i] = -1;
                }
            } else {
                if(this->canMove(mpId, srcCellId, -1, true, allowThroughEntity)) 
                    weights[i] = 100 + getOrientationDist(i, dir) + (!ignoreSpeed ?(mp->speed >= 0?5-mp->speed :11+abs(mp->speed)) :0);
                else 
                    weights[i] = -1;
            }
        } else {
            weights[i] = -1;
        }
    }

    int minWeightDir = -1;
    int minWeight = 10000;
    for(int i = 0; i < 8; i++) {
        if(weights[i] != -1 && weights[i] < minWeight && nearCells[i] != -1) {
            minWeight = weights[i];
            minWeightDir = i;
        }
    }

    if(minWeightDir != -1)
        return nearCells[minWeightDir];
    else if(allowItself && this->canMove(srcCellId, srcCellId, -1, true, allowThroughEntity))
        return srcCellId;

    return -1;
}


int AbstractMapManager::getOrientationDist(int dir1, int dir2) {
    return min(abs(dir2 - dir1), abs(8 - dir2 + dir1));
}

sp<ActorData> AbstractMapManager::getActor(double actorId) {
    auto actorIt = allActors.find(actorId);
    if(actorIt != allActors.end())
        return actorIt->second;

    return nullptr;
}

void AbstractMapManager::removeActor(double actorId) {
    allActors.erase(actorId);
}

// sp<RoleplayCharacterData> AbstractMapManager::getPlayer(double playerId) {
//     auto playerIt = players.find(playerId);
//     if(playerIt != players.end())
//         return playerIt->second.lock();

//     return nullptr;
// }

// sp<RoleplayNpcData> AbstractMapManager::getNpc(double npcId) {
//     auto npcIt = npcs.find(npcId);
//     if(npcIt != npcs.end())
//         return npcIt->second.lock();

//     return nullptr;
// }

// sp<RoleplayMonsterGroupData> AbstractMapManager::getMonsterGroup(double monsterGroupId) {
//     auto monsterGroupIt = monsterGroups.find(monsterGroupId);
//     if(monsterGroupIt != monsterGroups.end())
//         return monsterGroupIt->second.lock();

//     return nullptr;
// }

bool AbstractMapManager::updateActorPosition(double actorId, int newCellId) {

    auto actorIt = allActors.find(actorId);
    if(actorIt != allActors.end()) {
        actorIt->second->cellId = newCellId;
        return true;
    }

    return false;
}

// void AbstractMapManager::updateInteractiveElement(sp<InteractiveElement> interactive) {
//     auto interactiveIt = interactiveElements.find(interactive->elementId);
//     if(interactiveIt != interactiveElements.end()) {
//         interactiveIt->second->enabledSkills = interactive->enabledSkills;
//         interactiveIt->second->disabledSkills = interactive->disabledSkills;
//         interactiveIt->second->onCurrentMap = interactive->onCurrentMap;
//         interactiveIt->second->elementTypeId = interactive->elementTypeId;
//     } else {
//         interactiveElements[interactive->elementId] = interactive;
//     }
// }

// void AbstractMapManager::updateInteractiveElement(InteractiveElement interactive) {
//     auto interactiveIt = interactiveElements.find(interactive.elementId);
//     if(interactiveIt != interactiveElements.end()) {
//         interactiveIt->second->enabledSkills = interactive.enabledSkills;
//         interactiveIt->second->disabledSkills = interactive.disabledSkills;
//         interactiveIt->second->onCurrentMap = interactive.onCurrentMap;
//         interactiveIt->second->elementTypeId = interactive.elementTypeId;
//     } else {
//         interactiveElements[interactive.elementId] = make_shared<InteractiveElement>(interactive);
//     }
// }

// void AbstractMapManager::updateStatedElement(StatedElement stated) {
//     auto statedIt = statedElements.find(stated.elementId);
//     if(statedIt != statedElements.end()) {
//         statedIt->second.elementState = stated.elementState;
//         statedIt->second.onCurrentMap = stated.onCurrentMap;
//         statedIt->second.elementCellId = stated.elementCellId;
//     } else {
//         statedElements[stated.elementId] = stated;
//     }
// }

// int AbstractMapManager::getClosestCellIdFromVector(int cellId, vector<int> cells) {
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

bool AbstractMapManager::isCoordsInMap(int x, int y) {
    if(y >= -x && y <= x && y <= MAP_WIDTH + 13 - x)
        return y >= x - (MAP_HEIGHT - (-19));

    return false;
}

int AbstractMapManager::cellSpecialEffects(int x, int y) {
    if(this->isCoordsInMap(x, y)) {
        return this->getCell(position_to_cellId(x, y))->specialEffects;
    } else {
        return 0;
    }
}

void AbstractMapManager::setCellSpecialEffects(int x, int y, int specialEffects) {
    if(this->isCoordsInMap(x, y)) {
        this->getCell(position_to_cellId(x, y))->specialEffects = specialEffects;
    }
}

void AbstractMapManager::addMark(GameActionMark actionMark) {
    auto markIt = marks.find(actionMark.markId);
    if(markIt == marks.end() || markIt->second->cells.size() == 0) {
        sp<Mark> mark(new Mark(actionMark.markId, actionMark.markType));
        
        if(actionMark.cells.size() > 0) {
            GameActionMarkedCell markedCell = actionMark.cells[0];
            vector<int> selection;
            // 1 corresponds to GameActionMarkCellsTypeEnum.CELLS_CROSS 
            if(markedCell.cellsType == 1) {
                selection = ZoneBuilder::Cross(markedCell.cellId, 0, markedCell.zoneSize, this);
            } else if (markedCell.zoneSize > 0) {
                selection = ZoneBuilder::Lozenge(markedCell.cellId, 0, markedCell.zoneSize, this);
            } else {
                for(auto cell : actionMark.cells)
                    selection.push_back(cell.cellId);
            }

            mark->cells = selection;
            // 2 corresponds to GameActionMarkTypeEnum.TRAP
            if(mark->type == 2) 
                for(int cellId : selection) {
                    if(this->isInMap(cellId))
                        cells[cellId]->nbMarks ++;
                    else 
                        Logger::write("There is a zone with incorrect cellIds (" + to_string(cellId) + ").", LOG_ERROR);
                }
        }
        marks[mark->id] = mark;
        this->updateMarksInformations();
    }
}

void AbstractMapManager::removeMark(int markId) {
    auto markIt = marks.find(markId);
    if(markIt != marks.end()) {
        // 2 corresponds to GameActionMarkTypeEnum.TRAP
        if(markIt->second->type == 2) {
            for(int cellId : markIt->second->cells) {
                cells[cellId]->nbMarks--;
            }
        }

        marks.erase(markIt);
        this->updateMarksInformations();
    }
}

void AbstractMapManager::updateMarksInformations() {
    vector<int> cellMarks = vector<int>(cells.size(), 0);

    for(auto mark : marks) {
        for(int cellId : mark.second->cells)
            cellMarks[cellId] |= mark.second->type;
    }

    for(int i = 0; i < cells.size(); i++) {
        cells[i]->specialEffects = ((cells[i]->specialEffects | 3) ^ 3) | cellMarks[i];
    }
}