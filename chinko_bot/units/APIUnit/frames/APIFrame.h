#ifndef API_FRAME_H
#define API_FRAME_H

#include "Frame.h"
#include "APIUnit.h"

class APIFrame : public Frame {
public:
    // Constructor
    APIFrame() {};
    // Copy constructor
    APIFrame(const APIFrame& other) = default;

    // Copy operator
    APIFrame& operator=(const APIFrame& other) = default;
    // Destructor
    ~APIFrame() = default;

    virtual bool setParent(MessagingUnit* parent) override;

    APIUnit* apiUnitParent = nullptr;
};

#endif