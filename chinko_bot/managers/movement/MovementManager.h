#ifndef MOVEMENT_MANAGER_H
#define MOVEMENT_MANAGER_H

#include "Pathfinding.h"
#include "CurrentMapManager.h"
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

    int pathfindToCellInVectorRandom(vector<int> cells);

    void setBot(DofusBotUnit* bot) { this->bot = bot; };

protected:
    DofusBotUnit* bot = nullptr;
};

#endif