#ifndef CHANGETO_DOWN_MAP_BOTCOMMAND_H
#define CHANGETO_DOWN_MAP_BOTCOMMAND_H

#include "BotCommand.h"

class ChangeToDownMapBotCommand : public BotCommand {
public:
    ChangeToDownMapBotCommand() {};
    ChangeToDownMapBotCommand(int floor) { this->floor = floor; };

    virtual int getCommandId() { return commandId; }
    static const unsigned int commandId = 11;  

    int floor = 0; 
};

#endif