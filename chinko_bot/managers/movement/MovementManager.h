#ifndef MOVEMENT_MANAGER_H
#define MOVEMENT_MANAGER_H

#include "Pathfinding.h"
#include "AbstractMapManager.h"
#include "DofusBotUnit.h"

class MovementManager {
public:
    // Constructor
    MovementManager() {};
    // Constructor with bot initialization
    MovementManager(DofusBotUnit* bot) { this->bot = bot; };
    // Copy constructor
    MovementManager(const MovementManager& other) = default;

    // Copy operator
    MovementManager& operator=(const MovementManager& other) = default;
    // Destructor
    ~MovementManager() = default;

    // Returns the cellId of a cell that can be pathfind to from an array to cell
    int pathfindToCellInVectorRandom(vector<int> cells);
    // Returns the cellId offseted by (xOffset, yOffset)
    int cellIdWithOffset(int cellId, int xOffset, int yOffset);

    // Sets DofusBotUnit
    void setBot(DofusBotUnit* bot) { this->bot = bot; };

protected:
    // DofusBotUnit
    DofusBotUnit* bot = nullptr;
};

#endif