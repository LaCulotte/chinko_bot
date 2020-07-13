#ifndef DOFUSBOT_FRAME_H
#define DOFUSBOT_FRAME_H

#include "Frame.h"

#include "DofusBotUnit.h"

class DofusBotUnit;
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

protected:
    // Fonction that stops completely the bot when there is a major error or when a complete reset is necessary
    // TODO : faire des tests
    void killBot();
};

#define FINISHED_DOFUSBOT_FRAME_H

#endif