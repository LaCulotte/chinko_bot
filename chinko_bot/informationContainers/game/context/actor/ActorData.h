#ifndef ACTOR_DATA_H
#define ACTOR_DATA_H

#include "std_include.h"

class ActorData {
public:
    // Constructor
    ActorData() {};
    // Copy constructor
    ActorData(const ActorData& other) = default;

    // Copy operator
    virtual ActorData& operator=(const ActorData& other) = default;
    // Destructor
    virtual ~ActorData() = default;

    double contextualId = 0;

    bool allowMovementThrough = false;

    bool canWalkTo = false;
    bool canWalkThrough = false;
    bool canSeeThrough = false;
    
    int cellId = 0;
    int direction = 0;
};

#endif