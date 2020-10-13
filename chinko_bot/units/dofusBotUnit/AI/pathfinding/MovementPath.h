#ifndef MOVEMENTPATH_H
#define MOVEMENTPATH_H

#include "std_include.h"
#include <algorithm>

using namespace std;
struct PathTile{
    int cellId = -1;
    PathTile* parentTile = nullptr;
    int lookDirection = 0;

    float cost = 0;
    float weight = 0;
    bool opened = false;
    bool closed = false;
};

class MovementPath {
public:
    // Constructor
    MovementPath() {};
    // Constructor with initialization by the end tile
    MovementPath(PathTile* endTile);
    // Copy constructor
    MovementPath(const MovementPath& other) = default;

    // Copy operator
    MovementPath& operator=(const MovementPath& other) = default;
    // Desctructor
    ~MovementPath();

    vector<int> toKeyMovements();
    // n must be > 0
    int getNthTile(int n);
    double time;

    vector<PathTile *> path;
};

#endif