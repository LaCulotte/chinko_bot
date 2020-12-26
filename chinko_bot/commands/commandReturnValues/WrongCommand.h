#ifndef WRONG_COMMAND_H
#define WRONG_COMMAND_H

#include "BotCommandReturnValues.h"

// The bot command was not incorrect or its arguments are invalid 
class WrongCommand : public BotCommandReturnValues {
public:
    // Constructor
    WrongCommand() {};
};

#endif