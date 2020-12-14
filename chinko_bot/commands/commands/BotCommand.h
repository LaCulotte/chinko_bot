#ifndef BOTCOMMAND_H
#define BOTCOMMAND_H

class BotCommand {
public:
    virtual ~BotCommand() = default;

    virtual int getCommandId() { return commandId; }
    static const unsigned int commandId = 0;   

    int commandNumber = 0; 
};

#endif