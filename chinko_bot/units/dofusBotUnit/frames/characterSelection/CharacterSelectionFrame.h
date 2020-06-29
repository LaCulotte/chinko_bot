#ifndef CHARACTERSELECTION_FRAME_H
#define CHARACTERSELECTION_FRAME_H

#include "Frame.h"
#include "DofusBotUnit.h"
#include "APIUnit.h"

#include "SendPacketRequestMessage.h"
#include "SendPacketSuccessMessage.h"
#include "SendPacketFailureMessage.h"
#include "UnknownDofusMessage.h"

#include "BeginCharacterSelectionMessage.h"

#include "CharactersListRequestMessage.h"
#include "BasicCharactersListMessage.h"
#include "CharactersListMessage.h"
#include "CharacterSelectionMessage.h"
#include "CharacterSelectedSuccessMessage.h"
#include "CharacterSelectedErrorMessage.h"
#include "CharacterLoadingCompleteMessage.h"

// TODO : à enlever
#include "InventoryContentMessage.h"
#include "InventoryWeightMessage.h"
#include "ShortcutBarContentMessage.h"
#include "JobExperienceMultiUpdateMessage.h"
#include "AlmanachCalendarDateMessage.h"
#include "CharacterExperienceGainMessage.h"
#include "SpellListMessage.h"

enum CharacterSelectionFrameState {
    csf_idle,
    snd_CharactersListRequestMessage,
    rcv_CharactersListMessage,
    snd_CharacterSelectionMessage,
    rcv_CharacterSelectionResultMessage,
    rcv_CharacterLoadingCompleteMessage
};

class CharacterSelectionFrame : public Frame {
public: 
    // Constructor
    CharacterSelectionFrame() : Frame() {};
    // Copy constructor
    CharacterSelectionFrame(const CharacterSelectionFrame& other) = default;

    // Copy operator
    CharacterSelectionFrame& operator=(const CharacterSelectionFrame& other) = default;
    // Destructor
    ~CharacterSelectionFrame() = default;

    virtual bool computeMessage(sp<Message> message, int srcId) override;

    virtual bool setParent(MessagingUnit* parent) override;

    DofusBotUnit *dofusBotParent = nullptr;
protected: 
    CharacterSelectionFrameState currentState = csf_idle;

    bool handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message);
    bool handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message);
};



#endif