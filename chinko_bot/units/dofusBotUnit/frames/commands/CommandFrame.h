#ifndef COMMAND_FRAME_H
#define COMMAND_FRAME_H

#include "DofusBotFrame.h"

#include "BotCommandMessage.h"
#include "BotCommandReturnValuesMessage.h"

enum CommandFrameState {
    cf_idle,
    cf_changeMap,
    cf_collectInteractives
};

class CommandFrame : public DofusBotFrame {
public: 
    // Constructor
    CommandFrame() {};
    // Copy constructor
    CommandFrame(const CommandFrame& other) = default;

    // Copy operator
    CommandFrame& operator=(const CommandFrame& other) = default;
    // Destructor
    ~CommandFrame() = default;
    
    virtual bool computeMessage(sp<Message> message, int srcId) override;

protected:
    // Process a BotCommand
    void processCommand(sp<BotCommand> command);
    // Sends a return value
    void sendReturnValues(sp<BotCommandReturnValues> returnValues);

    // Alternative computeMessage depending on which command is being processed
    bool computeMessage_idle(sp<Message> message, int srcId);
    bool computeMessage_changeMap(sp<Message> message, int srcId);
    bool computeMessage_collectInteractives(sp<Message> message, int srcId);

    // Frame's state : reflect what command is being processed
    CommandFrameState currentState = cf_idle;

    // Current processed command 
    sp<BotCommand> currentProcessedCommand = nullptr;
    // Current processed command number
    int processedCommandNumber;
    // True if the bot is in a fight. Cannot send any command while the bot is in a fight.
    bool inFight = false;
};

#endif