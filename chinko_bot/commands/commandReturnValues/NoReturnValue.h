#ifndef NO_RETURNVALUE_H
#define NO_RETURNVALUE_H

#include "BotCommandReturnValues.h"

// Returns nothing, but the command has ended.
class NoReturnValue : public BotCommandReturnValues {
public:
    // Constructor
    NoReturnValue() {};
};

#endif