#include "DofusMessageTypeHandler.h"

DofusMessageTypeHandler::DofusMessageTypeHandler(){
    // Inits the map : message's id -> message builder
    id_to_builder[UnknownDofusMessage::protocolId] = make_shared<UnknownDofusMessage>;
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