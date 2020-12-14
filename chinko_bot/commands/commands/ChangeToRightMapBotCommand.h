#ifndef CHANGETO_RIGHT_MAP_BOTCOMMAND_H
#define CHANGETO_RIGHT_MAP_BOTCOMMAND_H

#include "BotCommand.h"

class ChangeToRightMapBotCommand : public BotCommand {
public:
    ChangeToRightMapBotCommand() {};
    ChangeToRightMapBotCommand(int floor) { this->floor = floor; };

    virtual int getCommandId() { return commandId; }
    static const unsigned int commandId = 12;   

    int floor = 0;
};

#endif