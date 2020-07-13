#ifndef DOFUS_MESSAGETYPEHANDLER_H
#define DOFUS_MESSAGETYPEHANDLER_H

#include "MessageTypeHandler.h"
#include <functional>
#include <unordered_map>

#include "UnknownDofusMessage.h"
#include "ProtocolRequiredMessage.h"
#include "HelloConnectMessage.h"
#include "IdentificationMessage.h"
#include "IdentificationSuccessMessage.h"
#include "ClientKeyMessage.h"
#include "CredentialsAknowledgementMessage.h"
#include "LoginQueueStatusMessage.h"
#include "SelectedServerDataExtendedMessage.h"
#include "SelectedServerDataMessage.h"

#include "HelloGameMessage.h"
#include "AuthentificationTicketMessage.h"
#include "RawDataMessage.h"
#include "CheckIntegrityMessage.h"
#include "AuthentificationTicketAcceptedMessage.h"
#include "CharactersListRequestMessage.h"
#include "BasicCharactersListMessage.h"
#include "CharactersListMessage.h"
#include "CharacterSelectionMessage.h"
#include "QueueStatusMessage.h"
#include "CharacterSelectedSuccessMessage.h"
#include "CharacterSelectedErrorMessage.h"
#include "CharacterLoadingCompleteMessage.h"

#include "InventoryContentMessage.h"
#include "InventoryWeightMessage.h"
#include "ShortcutBarContentMessage.h"
#include "JobExperienceMultiUpdateMessage.h"
#include "SequenceNumberRequestMessage.h"
#include "SequenceNumberMessage.h"
#include "AlmanachCalendarDateMessage.h"
#include "CharacterExperienceGainMessage.h"
#include "SpellListMessage.h"

#include "GameContextCreateRequestMessage.h"
#include "GameContextCreateMessage.h"
#include "CurrentMapMessage.h"
#include "MapInformationsRequestMessage.h"

class DofusMessageTypeHandler : public MessageTypeHandler {
public:
    // Constructor
    DofusMessageTypeHandler();
    // Copy constructor
    DofusMessageTypeHandler(const DofusMessageTypeHandler& other) = delete;

    // Copy operator
    DofusMessageTypeHandler& operator=(const DofusMessageTypeHandler& other) = delete;
    // Destructor
    virtual ~DofusMessageTypeHandler() {};

    // TODO : rename to build
    // Builds a message from the message's id
    virtual sp<Message> generateMessageById(int id) override;

protected:
    // Map that links a message id to a fonction to build the message
    unordered_map<int, function<sp<Message>()>> id_to_builder;
};

#endif