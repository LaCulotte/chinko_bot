#ifndef LOG_BOTCOMMAND_H
#define LOG_BOTCOMMAND_H

#include "BotCommand.h"
#include "std_include.h"

// Command to log some things on the bot Logger
class LogBotCommand : public BotCommand {
public:
    // Constructor
    LogBotCommand(string log) { this->log = log; }

    // Identifier for the type of the command
    virtual int getCommandId() { return commandId; }
    static const unsigned int commandId = 1;   

    // String to log
    string log;
};

#endif