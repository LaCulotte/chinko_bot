#ifndef CHANGETO_LEFT_MAP_BOTCOMMAND_H
#define CHANGETO_LEFT_MAP_BOTCOMMAND_H

#include "BotCommand.h"

// Command to make the player move to the left map
class ChangeToLeftMapBotCommand : public BotCommand {
public:
    // Constructor
    ChangeToLeftMapBotCommand() {};
    // Constructor with floor initialization
    ChangeToLeftMapBotCommand(int floor) { this->floor = floor; };

    // Identifier for the type of the command
    virtual int getCommandId() { return commandId; }
    static const unsigned int commandId = 13;

    // Floor of the tiles on which the player will change map
    int floor = 0;   
};

#endif