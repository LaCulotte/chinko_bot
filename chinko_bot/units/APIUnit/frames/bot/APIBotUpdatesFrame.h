#ifndef API_BOT_UPDATES_FRAME_H
#define API_BOT_UPDATES_FRAME_H

#include "APIFrame.h"

class APIBotUpdatesFrame : public APIFrame {
public :
    // Constructor
    APIBotUpdatesFrame() : APIFrame() {};
    // Copy constructor
    APIBotUpdatesFrame(const APIBotUpdatesFrame& other) = default;

    // Copy operator
    APIBotUpdatesFrame& operator=(const APIBotUpdatesFrame& other) = default;
    // Destructor
    ~APIBotUpdatesFrame() = default;

    virtual bool computeMessage(sp<Message> message, int srcId) override;

protected:
    vector<pair<int, int>> updateMessagesIdRanges = {{11030, 11037}};
};

#endif