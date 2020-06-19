#ifndef QUEUE_FRAME_H
#define QUEUE_FRAME_H

#include "Frame.h"

#include "LoginQueueStatusMessage.h"
#include "QueueStatusMessage.h"

class QueueFrame : public Frame {
public: 
    // Constructor
    QueueFrame() : Frame() {};
    // Copy constructor
    QueueFrame(const QueueFrame& other) = default;

    // Copy operator
    QueueFrame& operator=(const QueueFrame& other) = default;
    // Destructor
    ~QueueFrame() = default;

    virtual bool computeMessage(sp<Message> message, int srcId) override;  
};

#endif