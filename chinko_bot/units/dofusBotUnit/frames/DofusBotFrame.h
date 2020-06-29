#ifndef DOFUSBOT_FRAME_H
#define DOFUSBOT_FRAME_H

#include "Frame.h"

#include "DofusBotUnit.h"

class DofusBotFrame : public virtual Frame {
public:
    // Constructor
    DofusBotFrame() : Frame() {};
    // Copy constructor
    DofusBotFrame(const DofusBotFrame& other) = default;

    // Copy operator
    DofusBotFrame& operator=(const DofusBotFrame& other) = default;
    // Destructor
    ~DofusBotFrame() = default;

    virtual bool setParent(MessagingUnit* parent) override;

    DofusBotUnit* dofusBotParent = nullptr;  
};

#endif