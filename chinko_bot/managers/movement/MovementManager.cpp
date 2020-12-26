#include "MovementManager.h"

int MovementManager::pathfindToCellInVectorRandom(vector<int> cells) {
    if(!bot || !bot->playedCharacter)
        return -1;

    while(cells.size() > 0) {
        // Tries to pathfinding to a random cell
        int destinationCell_i = rand() % cells.size();
        int destinationCellId = cells[destinationCell_i];
        MovementPath path = PathFinding::findPath(bot->mapInfos, bot->playedCharacter->cellId, destinationCellId);

        if((path.toKeyMovements().back() & 0xFFF) == destinationCellId)
            // If you can pathfind to it, returns it
            return destinationCellId;

        // Else, removes it to the possible cells to pathfind to
        cells.erase(cells.begin() + destinationCell_i);
    }
    
    return -1;
}

int MovementManager::cellIdWithOffset(int cellId, int xOffset, int yOffset) {
    if(!bot || !bot->mapInfos) 
        return -1;

    // Gets the cell's coordinates 
    int x = bot->mapInfos->cellId_to_XPosition(cellId) + xOffset; 
    int y = bot->mapInfos->cellId_to_YPosition(cellId) + yOffset; 

    if(bot->mapInfos->isCoordsInMap(x, y)) {
        // Gets offseted cell
        int offsetCellId = bot->mapInfos->position_to_cellId(x, y);
        if(bot->mapInfos->isInMap(offsetCellId))
            // If it is in the map, returns it
            return offsetCellId;
    }

    return -1;
}