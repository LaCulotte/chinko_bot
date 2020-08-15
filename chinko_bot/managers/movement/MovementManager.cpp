#include "MovementManager.h"

int MovementManager::pathfindToCellInVectorRandom(vector<int> cells) {
    if(!bot || !bot->playedCharacter)
        return -1;

    while(cells.size() > 0) {
        int destinationCell_i = rand() % cells.size();
        int destinationCellId = cells[destinationCell_i];
        MovementPath path = PathFinding::findPath(&bot->mapInfos, bot->playedCharacter->cellId, destinationCellId);

        if((path.toKeyMovements().back() & 0xFFF) == destinationCellId)
            return destinationCellId;

        cells.erase(cells.begin() + destinationCell_i);
    }
    
    return -1;
}

int MovementManager::cellIdWithOffset(int cellId, int xOffset, int yOffset) {
    if(!bot) 
        return -1;

    int x = bot->mapInfos.cellId_to_XPosition(cellId) + xOffset; 
    int y = bot->mapInfos.cellId_to_YPosition(cellId) + yOffset; 

    if(bot->mapInfos.isCoordsInMap(x, y)) {
        int offsetCellId = bot->mapInfos.position_to_cellId(x, y);
        if(bot->mapInfos.isInMap(offsetCellId))
            return offsetCellId;
    }

    return -1;
}