#ifndef WEIGHT_RETURNVALUES_H
#define WEIGHT_RETURNVALUES_H

#include "BotCommandReturnValues.h"

// Returning the weight and max weight of the player
class WeightReturnValues : public BotCommandReturnValues {
public:
    // Constructor
    WeightReturnValues() {};
    // Constructor with weight initialization
    WeightReturnValues(int weight, int weightMax) { this->weight = weight; this->weightMax = weightMax; };

    int weight = 0;
    int weightMax = 0;
};

#endif