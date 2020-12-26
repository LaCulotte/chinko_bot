#include "Pathfinding.h"

#define HV_COST     10
#define DIAG_COST   15
#define HEURISTIC_COST 10

// TODO : support allowThroughEntitites = false
MovementPath PathFinding::findPath(sp<AbstractMapManager> map, int startCellId, int endCellId, bool allowDiags, bool avoidObstacles, bool allowThroughEntities){
    // Translation from the dofus' source code

    if(!map) {
        Logger::write("Cannot pathfind : no map provided.", LOG_ERROR);
        return MovementPath();
    }
    
    if(!map->isInMap(startCellId) || !map->isInMap(endCellId)){
        Logger::write("Cannot pathfind : starting or ending cell is not in the map.", LOG_ERROR);
        return MovementPath();
    }

    vector<PathTile *> tiles;
    for(int i = 0; i < map->getCellsCount(); i++) {
        PathTile* tile = new PathTile();
        tile->cellId = i;
        tiles.push_back(tile);
    }

    unordered_set<PathTile *> openTiles = { tiles[startCellId] };
    bool arrived = false;

    int bestDistanceToEnd = map->getManhattanDistance(startCellId, endCellId);
    int cellIdBestDistanceToEnd = startCellId;

    while(openTiles.size() > 0 && !tiles[endCellId]->closed) {
        PathTile* parent = *openTiles.begin();
        int minWeight = parent->weight;

        for (PathTile* tile : openTiles) {
            if(tile->weight < minWeight) {
                parent = tile;
                minWeight = tile->weight;
            }
        }

        int parentX = map->cellId_to_XPosition(parent->cellId);
        int parentY = map->cellId_to_YPosition(parent->cellId);
        
        openTiles.erase(parent);
        parent->closed = true;

        for(int x = parentX - 1; x < parentX + 2; x++) {
            for(int y = parentY - 1; y < parentY + 2; y++) {
                if(!map->isCoordsInMap(x, y))
                    continue;

                int cellId = map->position_to_cellId(x, y);

                if(!map->isInMap(cellId) || cellId == parent->cellId)
                    continue;
                
                PathTile* currentTile = tiles[cellId];
                // TODO : à mettre dans une fonction
                if(!currentTile->closed && map->canMove(cellId, parent->cellId, avoidObstacles, allowThroughEntities) &&
                   (y == parentY || x == parentX || 
                   allowDiags && (map->canMove(map->position_to_cellId(parentX, y), parent->cellId, avoidObstacles, allowThroughEntities) 
                               || map->canMove(map->position_to_cellId(x, parentY), parent->cellId, avoidObstacles, allowThroughEntities)))) {
                 
                    
                    float tileWeight = 0;
                    if(cellId == endCellId) {
                        tileWeight = 1;
                    } else  {
                        int speed = map->getCell(cellId)->speed;
                        if(allowThroughEntities) {
                            if(map->isThereBlockingEntityOn(cellId, allowThroughEntities)) 
                                tileWeight = 20;
                            else if (speed >= 0)
                                tileWeight = 6 - speed;
                            else 
                                tileWeight = 12 + abs(speed);
                        } else {
                            tileWeight = 1;
                            if(map->isThereBlockingEntityOn(cellId)) {
                                tileWeight += 0.3;
                            }
                            if(map->isCoordsInMap(x+1, y) && map->isThereBlockingEntityOn(map->position_to_cellId(x+1, y))) {
                                tileWeight += 0.3;
                            }
                            if(map->isCoordsInMap(x, y+1) && map->isThereBlockingEntityOn(map->position_to_cellId(x, y+1))) {
                                tileWeight += 0.3;
                            }
                            if(map->isCoordsInMap(x-1, y) && map->isThereBlockingEntityOn(map->position_to_cellId(x-1, y))) {
                                tileWeight += 0.3;
                            }
                            if(map->isCoordsInMap(x, y-1) && map->isThereBlockingEntityOn(map->position_to_cellId(x, y-1))) {
                                tileWeight += 0.3;
                            }
                            // TODO : ne pas oublier ca
                            if (map->cellSpecialEffects(x, y) & 2 == 2) {
                                tileWeight += 0.3;
                            }
                        }
                    }

                    float movementCost = parent->cost + ((x == parentX || y == parentY)?HV_COST:DIAG_COST) * tileWeight;
                    if(allowThroughEntities) {
                        // TODO : mettre en haut au lieu de tt le temps le calculer
                        int startX = map->cellId_to_XPosition(startCellId);
                        int startY = map->cellId_to_YPosition(startCellId);
                        int endX = map->cellId_to_XPosition(endCellId);
                        int endY = map->cellId_to_YPosition(endCellId);

                        bool cellOnStartColumn = (x + y == startX + startY);
                        bool cellOnEndColumn = (x + y == endX + endY);
                        bool cellOnStartLine = (x - y == startX - startY);
                        bool cellOnEndLine = (x - y == endX - endY);

                        if(!cellOnEndColumn && !cellOnEndLine || !cellOnStartColumn && !cellOnStartLine) { 
                            movementCost += map->getManhattanDistance(cellId, endCellId);
                            movementCost += map->getManhattanDistance(cellId, startCellId);
                        }

                        if(x == endX || y == endY)
                            movementCost -= 3;
                        if(x == startX || y == startY)
                            movementCost -= 3;
                        if(cellOnEndLine || cellOnEndColumn || x + y == parentX + parentY|| x - y == parentX - parentY)
                            movementCost -= 2;
                        if(cellOnStartColumn || cellOnStartLine)
                            movementCost -= 2;

                        int currentDistanceToEnd = map->getManhattanDistance(cellId, endCellId);
                        if(currentDistanceToEnd < bestDistanceToEnd) {
                            bestDistanceToEnd  = currentDistanceToEnd;
                            cellIdBestDistanceToEnd = cellId;
                        }
                    }

                    if(!currentTile->parentTile || movementCost < currentTile->cost) {
                        currentTile->parentTile = parent;
                        currentTile->cost = movementCost;
                        float heuristic = HEURISTIC_COST * map->getEuclidianDistance(cellId, endCellId);
                        currentTile->weight = heuristic + movementCost;

                        openTiles.insert(currentTile);
                    }
                }
            }
        }
    }

    PathTile* endTile = tiles[endCellId];
    if(!endTile->parentTile) {
        endTile = tiles[cellIdBestDistanceToEnd];
    }

    for(PathTile* tile = endTile; tile != nullptr; tile = tile->parentTile) {
        if(allowDiags) {
            PathTile* parent = tile->parentTile;
            PathTile* grandParent = parent?parent->parentTile:nullptr;
            PathTile* grandGrandParent = grandParent?grandParent->parentTile:nullptr;
            
            int tileX = map->cellId_to_XPosition(tile->cellId);
            int tileY = map->cellId_to_YPosition(tile->cellId);

            if(grandParent && map->getManhattanDistance(tile->cellId, grandParent->cellId) == 1) {
                if(map->canMove(tile->cellId, grandParent->cellId, avoidObstacles, allowThroughEntities))
                    tile->parentTile = grandParent;
            } else if (grandGrandParent && map->getManhattanDistance(tile->cellId, grandGrandParent->cellId) == 2) {
                // TODO : check si c'est vraiment un calcul valide
                int ggparentX = map->cellId_to_XPosition(grandGrandParent->cellId);
                int ggparentY = map->cellId_to_YPosition(grandGrandParent->cellId);
                int interX = tileX + as3_round(((float) (ggparentX - tileX)) / 2);
                int interY = tileY + as3_round(((float) (ggparentY - tileY)) / 2);

                if(map->canMove(map->position_to_cellId(interX, interY), tile->cellId, avoidObstacles, allowThroughEntities) && alternativePointWeight(tile->cellId, map) < 2)
                    tile->parentTile = tiles[map->position_to_cellId(interX, interY)];

            } else if(grandParent && map->getManhattanDistance(tile->cellId, grandParent->cellId) == 1) {
                int gparentX = map->cellId_to_XPosition(grandParent->cellId);
                int gparentY = map->cellId_to_YPosition(grandParent->cellId);
                int interX = tileX + as3_round(((float) (gparentX - tileX)) / 2);
                int interY = tileY + as3_round(((float) (gparentY - tileY)) / 2);
                int interCellId = map->position_to_cellId(interX, interY);

                if(tileX + tileY == gparentX + gparentY && tileX - tileY != interX - interY && !map->isChangeZone(tile->cellId, interCellId) && !map->isChangeZone(grandParent->cellId, interCellId))
                    tile->parentTile = grandParent;
                else if(tileX - tileY == gparentX - gparentY && tileX - tileY != interX - interY && !map->isChangeZone(tile->cellId, interCellId) && !map->isChangeZone(grandParent->cellId, interCellId))
                    tile->parentTile = grandParent;
                else if(tileX == gparentX && tileX != interX && alternativePointWeight(map->position_to_cellId(tileX, interY), map) < 2 && map->canMove(map->position_to_cellId(tileX, interY), tile->cellId, avoidObstacles, allowThroughEntities))
                    tile->parentTile = tiles[map->position_to_cellId(tileX, interY)];
                else if(tileY == gparentY && tileY != interY && alternativePointWeight(map->position_to_cellId(interX, tileY), map) < 2 && map->canMove(map->position_to_cellId(interX, tileY), tile->cellId, avoidObstacles, allowThroughEntities))
                    tile->parentTile = tiles[map->position_to_cellId(interX, tileY)];
            }

        }

        if (tile->parentTile) {
            tile->parentTile->lookDirection = map->getLookDirection(tile->parentTile->cellId, tile->cellId);

            if(tile == endTile)
                tile->lookDirection = map->getLookDirection(tile->parentTile->cellId, tile->cellId);
        }
    }

    return MovementPath(endTile);
}

float PathFinding::alternativePointWeight(int cellId, sp<AbstractMapManager> map, bool allowThroughEntities) {
    // Translation from dofus' source code 
    
    if(!map->isInMap(cellId)){
        Logger::write("Tried to compute the weight of an invalid cell", LOG_WARNING);
        return 10;
    }
    float weight = 1;
    if(allowThroughEntities) {
        int speed = map->getCell(cellId)->speed;
        if(speed >= 0) {
            weight += 5 - speed;
        } else {
            weight += 11 + abs(speed);
        }
        if(map->isThereBlockingEntityOn(cellId, allowThroughEntities)) {
            weight = 20;
        }
    } // TODO : else {}  <- never used

    return weight;
}