#include "APIMessageTypeHandler.h"
#include "APIMessageTypeIncludes.h"

APIMessageTypeHandler::APIMessageTypeHandler() {
    id_to_builder[APIHelloMessage::protocolId]                  = make_shared<APIHelloMessage>;
    id_to_builder[BeginAuthentificationMessage::protocolId]     = make_shared<BeginAuthentificationMessage>;
    id_to_builder[AuthentificationSuccessMessage::protocolId]   = make_shared<AuthentificationSuccessMessage>;
    id_to_builder[AuthentificationFailureMessage::protocolId]   = make_shared<AuthentificationFailureMessage>;

    id_to_builder[ServerInformationsListMessage::protocolId]    = make_shared<ServerInformationsListMessage>;
    id_to_builder[ServerSelectedMessage::protocolId]            = make_shared<ServerSelectedMessage>;
    id_to_builder[ServerSelectionSuccessMessage::protocolId]    = make_shared<ServerSelectionSuccessMessage>;
    id_to_builder[ServerSelectionFailureMessage::protocolId]    = make_shared<ServerSelectionFailureMessage>;

    id_to_builder[CharacterInformationsListMessage::protocolId]    = make_shared<CharacterInformationsListMessage>;
    id_to_builder[CharacterSelectedMessage::protocolId]            = make_shared<CharacterSelectedMessage>;
    id_to_builder[CharacterSelectionSuccessMessage::protocolId]    = make_shared<CharacterSelectionSuccessMessage>;
    id_to_builder[CharacterSelectionFailureMessage::protocolId]    = make_shared<CharacterSelectionFailureMessage>;

    id_to_builder[ItemsAddMessage::protocolId]                          = make_shared<ItemsAddMessage>;
    id_to_builder[JobsInformationsMessage::protocolId]                  = make_shared<JobsInformationsMessage>;
    id_to_builder[JobsXpMessage::protocolId]                            = make_shared<JobsXpMessage>;
    id_to_builder[PlayedCharacterInformationsMessage::protocolId]       = make_shared<PlayedCharacterInformationsMessage>;
    id_to_builder[PlayedCharacterInventoryWeightMessage::protocolId]    = make_shared<PlayedCharacterInventoryWeightMessage>;
    id_to_builder[PlayedCharacterKamasMessage::protocolId]              = make_shared<PlayedCharacterKamasMessage>;
    id_to_builder[PlayedCharacterLevelMessage::protocolId]              = make_shared<PlayedCharacterLevelMessage>;
    id_to_builder[PlayedCharacterXpMessage::protocolId]                 = make_shared<PlayedCharacterXpMessage>;

}

sp<Message> APIMessageTypeHandler::generateMessageById(int id) {
    // Finds asked message's builder
    auto builderIt = id_to_builder.find(id);

    if(builderIt != id_to_builder.end() && builderIt->second) {
        // Message id was found and its builder is valid
        
        // Builds and returns the right message
        return builderIt->second();
    } else {
        // Message id was not found or the builder is not valid

        // Builds default message for debug
        return make_shared<UnknownAPIMessage>(id);
    }
}