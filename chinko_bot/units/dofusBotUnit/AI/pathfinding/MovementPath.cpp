#include "MovementPath.h"

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
