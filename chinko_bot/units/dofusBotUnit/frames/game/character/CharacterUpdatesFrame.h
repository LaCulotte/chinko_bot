#ifndef CHARACTERUPDATES_FRAME_H
#define CHARACTERUPDATES_FRAME_H

// #include "Fra"
#include "DofusBotFrame.h"

class CharacterUpdatesFrame : public DofusBotFrame {
public:
    // Constructor
    CharacterUpdatesFrame() : DofusBotFrame() {}; 
    // Copy constructor
    CharacterUpdatesFrame(const CharacterUpdatesFrame& other) = default;

    // Copy operator
    CharacterUpdatesFrame& operator=(const CharacterUpdatesFrame& other) = default;
    // Destructor
    ~CharacterUpdatesFrame() = default;

    bool computeMessage(sp<Message> message, int srcId) override;
};

#endif