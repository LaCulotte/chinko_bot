#include "NetworkTypeHandler.h"

NetworkTypeHandler * NetworkTypeHandler::typeHandler = nullptr;

NetworkTypeHandler::NetworkTypeHandler() {
    id_to_builder[GameServerInfo::typeId]                       = make_shared<GameServerInfo>;

    id_to_builder[AbstractCharacterInformation::typeId]         = make_shared<AbstractCharacterInformation>;
    id_to_builder[CharacterBaseInformations::typeId]            = make_shared<CharacterBaseInformations>;
    id_to_builder[CharacterBasicMinimalInformations::typeId]    = make_shared<CharacterBasicMinimalInformations>;
    id_to_builder[CharacterMinimalInformations::typeId]         = make_shared<CharacterMinimalInformations>;
    id_to_builder[CharacterMinimalPlusLookInformations::typeId] = make_shared<CharacterMinimalPlusLookInformations>;
    id_to_builder[CharacterHardcoreOrEpicInformations::typeId]  = make_shared<CharacterHardcoreOrEpicInformations>;
    id_to_builder[EntityLook::typeId]                           = make_shared<EntityLook>;
}

NetworkTypeHandler * NetworkTypeHandler::getInstance() {
    if(!NetworkTypeHandler::typeHandler)
        NetworkTypeHandler::typeHandler = new NetworkTypeHandler();

    return NetworkTypeHandler::typeHandler;
}

sp<NetworkType> NetworkTypeHandler::getTypeById(int id) {
    auto typeIt = id_to_builder.find(id);

    if(typeIt != id_to_builder.end())
        return typeIt->second();
    else
        return nullptr;
} 