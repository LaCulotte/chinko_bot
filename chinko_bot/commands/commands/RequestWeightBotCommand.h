#ifndef REQUEST_WEIGHT_BOTCOMMAND_H
#define REQUEST_WEIGHT_BOTCOMMAND_H

#include "BotCommand.h"

// Command to get the player's weight (and max weight)
class RequestWeightBotCommand : public BotCommand {
public:
    // Constructor
    RequestWeightBotCommand() {};

    // Identifier for the type of the command
    virtual int getCommandId() { return commandId; }
    static const unsigned int commandId = 20;  
};

#endif