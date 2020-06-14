#include "DofusMessageTypeHandler.h"

DofusMessageTypeHandler::DofusMessageTypeHandler(){
    // Inits the map : message's id -> message builder
    id_to_builder[ProtocolRequiredMessage::protocolId]              = make_shared<ProtocolRequiredMessage>;
    id_to_builder[HelloConnectMessage::protocolId]                  = make_shared<HelloConnectMessage>;
    id_to_builder[IdentificationMessage::protocolId]                = make_shared<IdentificationMessage>;
    id_to_builder[IdentificationSuccessMessage::protocolId]         = make_shared<IdentificationSuccessMessage>;
    id_to_builder[ClientKeyMessage::protocolId]                     = make_shared<ClientKeyMessage>;
    id_to_builder[CredentialsAcknowledgementMessage::protocolId]    = make_shared<CredentialsAcknowledgementMessage>;
    id_to_builder[LoginQueueStatusMessage::protocolId]              = make_shared<LoginQueueStatusMessage>;
    id_to_builder[SelectedServerDataMessage::protocolId]            = make_shared<SelectedServerDataMessage>;
    id_to_builder[SelectedServerDataExtendedMessage::protocolId]    = make_shared<SelectedServerDataExtendedMessage>;

    id_to_builder[HelloGameMessage::protocolId]                         = make_shared<HelloGameMessage>;
    id_to_builder[AuthentificationTicketMessage::protocolId]            = make_shared<AuthentificationTicketMessage>;
    id_to_builder[RawDataMessage::protocolId]                           = make_shared<RawDataMessage>;
    id_to_builder[CheckIntegrityMessage::protocolId]                    = make_shared<CheckIntegrityMessage>;
    id_to_builder[AuthentificationTicketMessage::protocolId]            = make_shared<AuthentificationTicketMessage>;
    id_to_builder[AuthentificationTicketAcceptedMessage::protocolId]    = make_shared<AuthentificationTicketAcceptedMessage>;
    id_to_builder[CharactersListRequestMessage::protocolId]             = make_shared<CharactersListRequestMessage>;
    id_to_builder[BasicCharactersListMessage::protocolId]               = make_shared<BasicCharactersListMessage>;
    id_to_builder[CharactersListMessage::protocolId]                    = make_shared<CharactersListMessage>;
    id_to_builder[CharacterSelectionMessage::protocolId]                = make_shared<CharacterSelectionMessage>;

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