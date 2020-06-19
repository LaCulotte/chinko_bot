#ifndef TERMINALPROMPT_FRAME_H
#define TERMINALPROMPT_FRAME_H

#include <unordered_map>

#include "Frame.h"
#include "APIUnit.h"

#include "CharactersListMessage.h"
#include "CharacterSelectionMessage.h"

class TerminalPromptFrame : public Frame {
public :
    // Constructor
    TerminalPromptFrame() : Frame() {};
    // Copy constructor
    TerminalPromptFrame(const TerminalPromptFrame& other) = default;

    // Copy operator
    TerminalPromptFrame& operator=(const TerminalPromptFrame& other) = default;
    // Destructor
    ~TerminalPromptFrame() = default;

    virtual bool computeMessage(sp<Message> message, int srcId) override;

    virtual bool setParent(MessagingUnit* parent) override;

protected:

    unordered_map<int, string> breed_idToString = {    {1, "Feca"}, {2, "Osamodas"},
                                                        {3, "Enutrof"}, {4, "Sram"},
                                                        {5, "Xelor"}, {6, "Ecaflip"},
                                                        {7, "Eniripsa"}, {8, "Iop"},
                                                        {9, "Cra"}, {10, "Sadida"},
                                                        {11, "Sacrier"}, {12, "Pandawa"},
                                                        {13, "Roublard"}, {14, "Zobal"},
                                                        {15, "Steamer"}, {16, "Eliotrope"},
                                                        {17, "Huppermage"}, {18, "Ouginiak"}    };
};

#endif