#ifndef CHARACTERSELECTION_FRAME_H
#define CHARACTERSELECTION_FRAME_H

#include "PacketSendingDofusBotFrame.h"
#include "DofusBotUnit.h"
#include "APIUnit.h"


#include "SendPacketRequestMessage.h"
#include "SendPacketSuccessMessage.h"
#include "SendPacketFailureMessage.h"
#include "UnknownDofusMessage.h"

#include "BeginCharacterSelectionMessage.h"
#include "SwitchContextFrame.h"
#include "BeginGameContextRequestMessage.h"

#include "CharactersListRequestMessage.h"
#include "BasicCharactersListMessage.h"
#include "CharactersListMessage.h"
#include "CharacterSelectionMessage.h"
#include "CharacterSelectedSuccessMessage.h"
#include "CharacterSelectedErrorMessage.h"
#include "CharacterLoadingCompleteMessage.h"
#include "ClientKeyMessage.h"

// TODO : à enlever
#include "InventoryContentMessage.h"
#include "InventoryWeightMessage.h"
#include "ShortcutBarContentMessage.h"
#include "JobExperienceMultiUpdateMessage.h"
#include "AlmanachCalendarDateMessage.h"
#include "CharacterExperienceGainMessage.h"
#include "SpellListMessage.h"

// States that the frame can be in; Keeps track of what to do next and if every thing is going in the right order
enum CharacterSelectionFrameState {
    csf_idle,
    snd_CharactersListRequestMessage,
    rcv_CharactersListMessage,
    snd_CharacterSelectionMessage,
    rcv_CharacterSelectionResultMessage,
    rcv_CharacterLoadingCompleteMessage
};

class CharacterSelectionFrame : public PacketSendingDofusBotFrame {
public: 
    // Constructor
    CharacterSelectionFrame() : PacketSendingDofusBotFrame() {};
    // Copy constructor
    CharacterSelectionFrame(const CharacterSelectionFrame& other) = default;

    // Copy operator
    CharacterSelectionFrame& operator=(const CharacterSelectionFrame& other) = default;
    // Destructor
    ~CharacterSelectionFrame() = default;

    virtual bool computeMessage(sp<Message> message, int srcId) override;

protected: 
    // Current state from the state
    CharacterSelectionFrameState currentState = csf_idle;

    bool handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message);
    bool handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message);

    // Sends CharactersListRequestMessage
    bool sendCharactersListRequestMessage();
    // Sends CharacterSelectionMessage
    bool sendCharacterSelectionMessage(sp<CharacterSelectionMessage> csMsg);
    // Sends ClientKeyMessage with hash at the end
    bool sendClientKeyMessageWithHash();
};



#endif