#ifndef BOTCOMMANDRETURNVALUES_H
#define BOTCOMMANDRETURNVALUES_H

// Virtual class for a return value for a BotCommand. 
class BotCommandReturnValues {
public:
    virtual ~BotCommandReturnValues() = default;

    // Number of the command to witch this return value is tied
    int commmandNumber = 0;  
};

#endif