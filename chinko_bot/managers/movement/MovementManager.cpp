#include "MovementManager.h"

int MovementManager::pathfindToCellInVectorRandom(vector<int> cells) {
    if(!bot || !bot->playedCharacer)
        return -1;

    while(cells.size() > 0) {
        int destinationCell_i = rand() % cells.size();
        int destinationCellId = cells[destinationCell_i];
        MovementPath path = PathFinding::findPath(&bot->mapInfos, bot->playedCharacer->cellId, destinationCellId);

        if((path.toKeyMovements().back() & 0xFFF) == destinationCellId)
            return destinationCellId;

        cells.erase(cells.begin() + destinationCell_i);
    }
    
    return -1;
}