#ifndef NETWORKTYPE_HANDLER_H
#define NETWORKTYPE_HANDLER_H

#include <unordered_map>
#include <functional>

#include "NetworkType.h"

#include "GameServerInfo.h"

#include "AbstractCharacterInformation.h"
#include "CharacterBaseInformations.h"
#include "CharacterBasicMinimalInformations.h"
#include "CharacterMinimalInformations.h"
#include "CharacterMinimalPlusLookInformations.h"
#include "CharacterHardcoreOrEpicInformations.h"
#include "EntityLook.h"

class NetworkTypeHandler {
public:
    static NetworkTypeHandler* getInstance();

    sp<NetworkType> getTypeById(int id);

private:
    NetworkTypeHandler();
    ~NetworkTypeHandler() = default;

    static NetworkTypeHandler* typeHandler;

    unordered_map<int, function<sp<NetworkType>()>> id_to_builder;
};

#endif