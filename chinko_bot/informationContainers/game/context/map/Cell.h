#ifndef CELL_H
#define CELL_H

#include "std_include.h"

class Cell {
public:
    // Constructor
    Cell() {};
    // Copy Constructor
    Cell(const Cell& other) = default;

    // Copy operator
    Cell& operator=(const Cell& other) = default;
    // Destructor
    ~Cell() = default;

    bool mov = false;
    bool isBlockedByObstacle = false;
    int floor = 0;
    int moveZone = 0;
    int speed = 0;

    int mapChangeData = 0;
    int linkedZone = 0;
};

#endif