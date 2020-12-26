#ifndef MOVEMENTPATH_H
#define MOVEMENTPATH_H

#include "std_include.h"
#include <algorithm>

using namespace std;
// Base tile; form a path when linked together 
struct PathTile{
    // Cell's id
    int cellId = -1;
    // Parent/Previous tile
    PathTile* parentTile = nullptr;
    // Direction towards the next tile
    int lookDirection = 0;

    // Infos for A* algorithm
    float cost = 0;
    float weight = 0;
    bool opened = false;
    bool closed = false;
};

// Path that is made of the necessary tiles that make a path
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

    // Turns the path into keyMovement, ready to be sent by the bot. 
    vector<int> toKeyMovements();
    // n must be > 0
    // Get the nth tile of the path
    int getNthTile(int n);

    // List of PathTiles that makes a full path
    vector<PathTile *> path;
};

#endif