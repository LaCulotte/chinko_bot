#ifndef REQUEST_WEIGHT_BOTCOMMAND_H
#define REQUEST_WEIGHT_BOTCOMMAND_H

#include "BotCommand.h"

class RequestWeightBotCommand : public BotCommand {
public:
    RequestWeightBotCommand() {};

    virtual int getCommandId() { return commandId; }
    static const unsigned int commandId = 20;  
};

#endif