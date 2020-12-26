#ifndef BOTCOMMAND_H
#define BOTCOMMAND_H

// Virutal class for a command that can be send to a BotUnit to be executed
class BotCommand {
public:
    virtual ~BotCommand() = default;

    // Identifier for the type of the command
    virtual int getCommandId() { return commandId; }
    static const unsigned int commandId = 0;   

    // Number of the command to be executed
    int commandNumber = 0; 
};

#endif