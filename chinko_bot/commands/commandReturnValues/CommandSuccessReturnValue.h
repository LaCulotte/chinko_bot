#ifndef COMMANDSUCCESS_RETURNVALUE_H
#define COMMANDSUCCESS_RETURNVALUE_H

#include "BotCommandReturnValues.h"

// Returns if the command was a success or not.
class CommandSuccessReturnValue : public BotCommandReturnValues {
public:
    // Constructor
    CommandSuccessReturnValue() {};
    // Constructor with success initialization
    CommandSuccessReturnValue(bool success) { this->success = success; };

    // Success of the command
    bool success = true;
};

#endif