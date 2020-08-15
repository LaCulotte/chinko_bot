#ifndef FIGHTER_DATA_H
#define FIGHTER_DATA_H

#include "ActorData.h"
#include "GameFightMinimalStats.h"

class FighterData : public ActorData {
    // Constructor
    FighterData() : ActorData() {};
    // Copy constructor
    FighterData(const FighterData& other) = default;

    // Copy operator
    virtual FighterData& operator=(const FighterData& other) = default;
    // Destructor
    virtual ~FighterData() = default;

   	sp<GameFightMinimalStats> stats;
};

#endif