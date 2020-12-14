#ifndef BOTCOMMANDRETURNVALUES_H
#define BOTCOMMANDRETURNVALUES_H

class BotCommandReturnValues {
public:
    virtual ~BotCommandReturnValues() = default;

    int commmandNumber = 0;  
};

#endif