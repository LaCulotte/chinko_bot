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
    int processedCommandNumber;

    void processCommand(sp<BotCommand> command);
    void sendReturnValues(sp<BotCommandReturnValues> returnValues);

    bool computeMessage_idle(sp<Message> message, int srcId);
    bool computeMessage_changeMap(sp<Message> message, int srcId);
    bool computeMessage_collectInteractives(sp<Message> message, int srcId);

    CommandFrameState currentState = cf_idle;

    sp<BotCommand> currentProcessedCommand = nullptr;
    bool inFight = false;
};

#endif