#ifndef CHANGETO_LEFT_MAP_BOTCOMMAND_H
#define CHANGETO_LEFT_MAP_BOTCOMMAND_H

#include "BotCommand.h"

class ChangeToLeftMapBotCommand : public BotCommand {
public:
    ChangeToLeftMapBotCommand() {};
    ChangeToLeftMapBotCommand(int floor) { this->floor = floor; };

    virtual int getCommandId() { return commandId; }
    static const unsigned int commandId = 13;

    int floor = 0;   
};

#endif