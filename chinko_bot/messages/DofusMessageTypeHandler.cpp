#include "DofusMessageTypeHandler.h"
#include "DofusMessageTypesIncludes.h"

DofusMessageTypeHandler::DofusMessageTypeHandler(){
    // Inits the map : message's id -> message builder
    id_to_builder[ProtocolRequired::protocolId]                     = make_shared<ProtocolRequired>;
    id_to_builder[HelloConnectMessage::protocolId]                  = make_shared<HelloConnectMessage>;
    id_to_builder[IdentificationMessage::protocolId]                = make_shared<IdentificationMessage>;
    id_to_builder[IdentificationSuccessMessage::protocolId]         = make_shared<IdentificationSuccessMessage>;
    id_to_builder[ClientKeyMessage::protocolId]                     = make_shared<ClientKeyMessage>;
    id_to_builder[CredentialsAcknowledgementMessage::protocolId]    = make_shared<CredentialsAcknowledgementMessage>;
    id_to_builder[LoginQueueStatusMessage::protocolId]              = make_shared<LoginQueueStatusMessage>;
    id_to_builder[SelectedServerDataMessage::protocolId]            = make_shared<SelectedServerDataMessage>;
    id_to_builder[SelectedServerDataExtendedMessage::protocolId]    = make_shared<SelectedServerDataExtendedMessage>;

    id_to_builder[HelloGameMessage::protocolId]                         = make_shared<HelloGameMessage>;
    id_to_builder[AuthenticationTicketMessage::protocolId]              = make_shared<AuthenticationTicketMessage>;
    id_to_builder[RawDataMessage::protocolId]                           = make_shared<RawDataMessage>;
    id_to_builder[CheckIntegrityMessage::protocolId]                    = make_shared<CheckIntegrityMessage>;
    id_to_builder[AuthenticationTicketAcceptedMessage::protocolId]      = make_shared<AuthenticationTicketAcceptedMessage>;
    id_to_builder[CharactersListRequestMessage::protocolId]             = make_shared<CharactersListRequestMessage>;
    id_to_builder[BasicCharactersListMessage::protocolId]               = make_shared<BasicCharactersListMessage>;
    id_to_builder[CharactersListMessage::protocolId]                    = make_shared<CharactersListMessage>;
    id_to_builder[CharacterSelectionMessage::protocolId]                = make_shared<CharacterSelectionMessage>;
    id_to_builder[QueueStatusMessage::protocolId]                       = make_shared<QueueStatusMessage>;
    id_to_builder[CharacterSelectedSuccessMessage::protocolId]          = make_shared<CharacterSelectedSuccessMessage>;
    id_to_builder[CharacterSelectedErrorMessage::protocolId]            = make_shared<CharacterSelectedErrorMessage>;
    id_to_builder[CharacterLoadingCompleteMessage::protocolId]          = make_shared<CharacterLoadingCompleteMessage>;

    id_to_builder[InventoryContentMessage::protocolId]              = make_shared<InventoryContentMessage>;
    id_to_builder[InventoryWeightMessage::protocolId]               = make_shared<InventoryWeightMessage>;
    id_to_builder[ShortcutBarContentMessage::protocolId]            = make_shared<ShortcutBarContentMessage>;
    id_to_builder[JobExperienceMultiUpdateMessage::protocolId]      = make_shared<JobExperienceMultiUpdateMessage>;
    id_to_builder[SequenceNumberRequestMessage::protocolId]         = make_shared<SequenceNumberRequestMessage>;
    id_to_builder[SequenceNumberMessage::protocolId]                = make_shared<SequenceNumberMessage>;
    id_to_builder[AlmanachCalendarDateMessage::protocolId]          = make_shared<AlmanachCalendarDateMessage>;
    id_to_builder[CharacterExperienceGainMessage::protocolId]       = make_shared<CharacterExperienceGainMessage>;
    id_to_builder[SpellListMessage::protocolId]                     = make_shared<SpellListMessage>;

    id_to_builder[GameContextCreateRequestMessage::protocolId]      = make_shared<GameContextCreateRequestMessage>;
    id_to_builder[GameContextCreateMessage::protocolId]             = make_shared<GameContextCreateMessage>;
    id_to_builder[CurrentMapMessage::protocolId]                    = make_shared<CurrentMapMessage>;

    id_to_builder[MapComplementaryInformationsDataMessage::protocolId]	= make_shared<MapComplementaryInformationsDataMessage>;

    id_to_builder[UnknownDofusMessage::protocolId]                  = make_shared<UnknownDofusMessage>;
}

sp<Message> DofusMessageTypeHandler::generateMessageById(int id) {

    // Finds asked message's builder
    auto builderIt = id_to_builder.find(id);

    if(builderIt != id_to_builder.end() && builderIt->second) {
        // Message id was found and its builder is valid
        
        // Builds and returns the right message
        return builderIt->second();
    } else {
        // Message id was not found or the builder is not valid

        // Builds default message for debug
        return make_shared<UnknownDofusMessage>(id);
    }
}