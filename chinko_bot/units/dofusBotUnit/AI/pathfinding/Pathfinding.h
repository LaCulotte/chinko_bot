#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "CurrentMapManager.h"
#include "MovementPath.h"

#include <unordered_set>
#include <math.h>

class PathFinding {
public:
    static MovementPath findPath(CurrentMapManager* map, int startCellId, int endCellId, bool allowDiags = true, bool avoidObstacles = true, bool allowThroughEntities = true);

private:
    // Constructor
    PathFinding() {};
    // Copy constructor
    PathFinding(const PathFinding& other) = default;

    // Copy operator
    PathFinding& operator=(const PathFinding& other) = default;
    // Destructor
    ~PathFinding() = default;

protected:
    static float alternativePointWeight(int cellId, CurrentMapManager* map, bool allowThroughEntity);
};

#endif