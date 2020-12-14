#ifndef COLLECTINTERACTIVES_BOTCOMMAND_H
#define COLLECTINTERACTIVES_BOTCOMMAND_H

#include "BotCommand.h"
#include "std_include.h"

class CollectInteractivesBotCommand : public BotCommand {
public:
    CollectInteractivesBotCommand() {};
    CollectInteractivesBotCommand(vector<int> interactives) { this->interactives = interactives; };

    virtual int getCommandId() { return commandId; }
    static const unsigned int commandId = 14; 

    vector<int> interactives;  
};

#endif