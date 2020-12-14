#ifndef SCIPT_FRAME_H
#define SCIPT_FRAME_H

#include "APIFrame.h"
#include "UpdatingFrame.h"

#include "ScriptManager.h"

class ScriptFrame : public APIFrame, public UpdatingFrame {
public:
    // Constructor
    ScriptFrame() : UpdatingFrame() {};
    // Copy constructor
    ScriptFrame(const ScriptFrame& other) = default;

    // Copy operator
    ScriptFrame& operator=(const ScriptFrame& other) = default;
    // Desctructor
    ~ScriptFrame() = default;

    bool computeMessage(sp<Message> message, int srcId) override;

    bool update() override;

protected:
    ScriptManager scriptManager;

    bool temp = false;
};

#endif