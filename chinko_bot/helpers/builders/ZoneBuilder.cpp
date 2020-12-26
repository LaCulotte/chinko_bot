#include "ZoneBuilder.h"

vector<int> ZoneBuilder::Cross(int centerCellId, int minRadius, int maxRadius, AbstractMapManager* mapManager) {
    vector<int> ret;

    if(minRadius == 0)
        ret.push_back(centerCellId);

    int xCenter = AbstractMapManager::cellId_to_XPosition(centerCellId);
    int yCenter = AbstractMapManager::cellId_to_YPosition(centerCellId);

    // Builds a cross of cells
    for(int r = maxRadius; r > 0 && r >= minRadius; r--) {
        if(AbstractMapManager::isCoordsInMap(xCenter + r, yCenter)) {
            if(!mapManager || mapManager->canMove(AbstractMapManager::position_to_cellId(xCenter + r, yCenter)))
                ret.push_back(AbstractMapManager::position_to_cellId(xCenter + r, yCenter));
        }
        if(AbstractMapManager::isCoordsInMap(xCenter - r, yCenter)) {
            if(!mapManager || mapManager->canMove(AbstractMapManager::position_to_cellId(xCenter - r, yCenter)))
                ret.push_back(AbstractMapManager::position_to_cellId(xCenter - r, yCenter));
        }
        if(AbstractMapManager::isCoordsInMap(xCenter, yCenter + r)) {
            if(!mapManager || mapManager->canMove(AbstractMapManager::position_to_cellId(xCenter, yCenter + r)))
                ret.push_back(AbstractMapManager::position_to_cellId(xCenter, yCenter + r));
        }
        if(AbstractMapManager::isCoordsInMap(xCenter, yCenter - r)) {
            if(!mapManager || mapManager->canMove(AbstractMapManager::position_to_cellId(xCenter, yCenter - r)))
                ret.push_back(AbstractMapManager::position_to_cellId(xCenter, yCenter - r));
        }
    }    

    return ret;
}

vector<int> ZoneBuilder::Lozenge(int centerCellId, int minRadius, int maxRadius, AbstractMapManager* mapManager) {
    vector<int> ret;

    if(maxRadius == 0) {
        if(minRadius == 0)
            ret.push_back(centerCellId);
        return ret;
    }

    int xCenter = AbstractMapManager::cellId_to_XPosition(centerCellId);
    int yCenter = AbstractMapManager::cellId_to_YPosition(centerCellId);

    // Builds a lozenge of cells and push them in the returning array
    for(int step = maxRadius; step >= minRadius; step--) {
        for(int i = -step; i <= step; i++) {
            for(int j = -step; j <= step; j++) {

                if(abs(i) + abs(j) == step)
                    if(AbstractMapManager::isCoordsInMap(xCenter + i, yCenter + j)) 
                        if(!mapManager || mapManager->canMove(AbstractMapManager::position_to_cellId(xCenter + i, yCenter + j)))
                            ret.push_back(AbstractMapManager::position_to_cellId(xCenter + i, yCenter + j));
            }
        }
    }    

    return ret;   
}