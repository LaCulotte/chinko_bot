#ifndef CHANGETO_UP_MAP_BOTCOMMAND_H
#define CHANGETO_UP_MAP_BOTCOMMAND_H

#include "BotCommand.h"

// Command to make the player move to the uo map
class ChangeToUpMapBotCommand : public BotCommand {
public:
    // Constructor
    ChangeToUpMapBotCommand() {};
    // Constructor with floor initialization
    ChangeToUpMapBotCommand(int floor) { this->floor = floor; };

    // Identifier for the type of the command
    virtual int getCommandId() { return commandId; }
    static const unsigned int commandId = 10;   

    // Floor of the tiles on which the player will change map
    int floor = 0;
};

#endif