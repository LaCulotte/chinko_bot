#ifndef CHANGETO_RIGHT_MAP_BOTCOMMAND_H
#define CHANGETO_RIGHT_MAP_BOTCOMMAND_H

#include "BotCommand.h"

// Command to make the player move to the right map
class ChangeToRightMapBotCommand : public BotCommand {
public:
    // Constructor
    ChangeToRightMapBotCommand() {};
    // Constructor with floor initialization
    ChangeToRightMapBotCommand(int floor) { this->floor = floor; };

    // Identifier for the type of the command
    virtual int getCommandId() { return commandId; }
    static const unsigned int commandId = 12;   

    // Floor of the tiles on which the player will change map
    int floor = 0;
};

#endif