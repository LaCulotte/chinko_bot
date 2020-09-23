#ifndef MARK_H
#define MARK_H

#include "std_include.h"

class Mark {
public:
    // Constructor
    Mark() {};
    // Constructor with data initialization
    Mark(int id, int type) { this->id = id; this->type = type; };
    // Copy Constructor
    Mark(const Mark& other) = default;

    // Copy operator
    Mark& operator=(const Mark& other) = default;
    // Destructor
    ~Mark() = default;

    int id = 0;
    int type = 0;
    // Contains the same cells as 'selection' (see ankamagames/dofus/logic/game/fight/types/MarkInstance.as)
    vector<int> cells;
};

#endif