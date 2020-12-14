#ifndef LOG_BOTCOMMAND_H
#define LOG_BOTCOMMAND_H

#include "BotCommand.h"
#include "std_include.h"

class LogBotCommand : public BotCommand {
public:
    LogBotCommand(string log) { this->log = log; }

    virtual int getCommandId() { return commandId; }
    static const unsigned int commandId = 1;   

    string log;
};

#endif