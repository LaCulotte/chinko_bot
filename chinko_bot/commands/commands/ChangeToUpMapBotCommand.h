#ifndef CHANGETO_UP_MAP_BOTCOMMAND_H
#define CHANGETO_UP_MAP_BOTCOMMAND_H

#include "BotCommand.h"

class ChangeToUpMapBotCommand : public BotCommand {
public:
    ChangeToUpMapBotCommand() {};
    ChangeToUpMapBotCommand(int floor) { this->floor = floor; };

    virtual int getCommandId() { return commandId; }
    static const unsigned int commandId = 10;   

    int floor = 0;
};

#endif