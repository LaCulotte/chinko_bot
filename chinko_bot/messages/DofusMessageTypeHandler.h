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

    virtual sp<Message> generateMessageById(int id) override;

protected:
    unordered_map<int, function<sp<Message>()>> id_to_builder;
};

#endif