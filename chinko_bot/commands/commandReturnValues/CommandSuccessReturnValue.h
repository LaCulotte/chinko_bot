#ifndef COMMANDSUCCESS_RETURNVALUE_H
#define COMMANDSUCCESS_RETURNVALUE_H

#include "BotCommandReturnValues.h"

class CommandSuccessReturnValue : public BotCommandReturnValues {
public:
    // Constructor
    CommandSuccessReturnValue() {};
    // Constructor with success initialization
    CommandSuccessReturnValue(bool success) { this->success = success; };

    bool success = true;
};

#endif