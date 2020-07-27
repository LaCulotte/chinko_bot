#ifndef TIME_FRAME_H
#define TIME_FRAME_H

#include "Frame.h"

#include "TimedMessage.h"

class TimeFrame : public Frame {
public:
    // Constructor
    TimeFrame() {};
    // Copy constructor
    TimeFrame(const TimeFrame& other) = default;

    // Copy operator
    TimeFrame& operator=(const TimeFrame& other) = default;
    // Destructor
    ~TimeFrame() = default;

    bool computeMessage(sp<Message> message, int srcId) override;
};

#endif