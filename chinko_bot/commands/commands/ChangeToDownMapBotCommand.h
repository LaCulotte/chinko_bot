#ifndef CHANGETO_DOWN_MAP_BOTCOMMAND_H
#define CHANGETO_DOWN_MAP_BOTCOMMAND_H

#include "BotCommand.h"

// Command to make the player move to the down map
class ChangeToDownMapBotCommand : public BotCommand {
public:
    // Constructor
    ChangeToDownMapBotCommand() {};
    // Constructor with floor initialization
    ChangeToDownMapBotCommand(int floor) { this->floor = floor; };

    // Identifier for the type of the command
    virtual int getCommandId() { return commandId; }
    static const unsigned int commandId = 11;  

    // Floor of the tiles on which the player will change map
    int floor = 0; 
};

#endif