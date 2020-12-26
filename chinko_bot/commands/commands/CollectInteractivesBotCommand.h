#ifndef COLLECTINTERACTIVES_BOTCOMMAND_H
#define COLLECTINTERACTIVES_BOTCOMMAND_H

#include "BotCommand.h"
#include "std_include.h"

// Bot command to collect all the interactives on the current map
class CollectInteractivesBotCommand : public BotCommand {
public:
    // Constructor
    CollectInteractivesBotCommand() {};
    // Constructor with interactives initialization
    CollectInteractivesBotCommand(vector<int> interactives) { this->interactives = interactives; };

    // Identifier for the type of the command
    virtual int getCommandId() { return commandId; }
    static const unsigned int commandId = 14; 

    // List of the interactives to collect on the map
    vector<int> interactives;  
};

#endif