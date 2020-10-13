#include "MovementPath.h"
#include "AbstractMapManager.h"

MovementPath::MovementPath(PathTile* endTile) {
    path.push_back(endTile);
    PathTile* toInsert = endTile->parentTile;
    PathTile* currentTile = endTile->parentTile;

    while(currentTile != nullptr) {
        if(currentTile->lookDirection != toInsert->lookDirection)
        //     toInsert = currentTile;
        // else 
            path.push_back(toInsert);

        toInsert = currentTile;
        currentTile = currentTile->parentTile;
    }

    if(toInsert)
        path.push_back(toInsert);
        
    reverse(path.begin(), path.end());
}

vector<int> MovementPath::toKeyMovements() {
    vector<int> ret;

    for(PathTile* tile : path)
        ret.push_back((tile->lookDirection << (4 * 3)) | tile->cellId);

    return ret;
}

MovementPath::~MovementPath() {
    for(PathTile* tile : path)
        delete tile;
}

// TODO : à perfectionner (plus propre? - sans passer par les coords)
int MovementPath::getNthTile(int n) {
    PathTile* currTile = path[0];
    int nextIndex = 1;
    int step = 0;
    int currCellId = currTile->cellId;

    while(step < n && nextIndex < path.size()) {

        int currCellX = AbstractMapManager::cellId_to_XPosition(currCellId);
        int currCellY = AbstractMapManager::cellId_to_YPosition(currCellId);

        switch (currTile->lookDirection)
        {
        case 0:
            currCellX++;
            currCellY++;
            break;
        case 1:
            currCellX++;
            break;
        case 2:
            currCellX++;
            currCellY--;
            break;
        case 3:
            currCellY--;
            break;
        case 4:
            currCellX--;
            currCellY--;
            break;  
        case 5:
            currCellX--;
            break;
        case 6:
            currCellX--;
            currCellY++;
            break;
        case 7:
            currCellX--;
            break;
        default:
            break;
        }

        currCellId = AbstractMapManager::position_to_cellId(currCellX, currCellY);

        if(currCellId == path[nextIndex]->cellId) {
            currTile = path[nextIndex];
            nextIndex++;
        }

        step++;
    }

    return currCellId;
}