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

#include "Item.h"
#include "ObjectItem.h"
#include "SpellItem.h"
#include "ObjectEffect.h"
#include "ObjectEffectCreature.h"
#include "ObjectEffectDate.h"
#include "ObjectEffectDice.h"
#include "ObjectEffectInteger.h"
#include "ObjectEffectLadder.h"
#include "ObjectEffectMinMax.h"
#include "ObjectEffectMount.h"
#include "ObjectEffectString.h"

#include "Shortcut.h"
#include "ShortcutEmote.h"
#include "ShortcutObject.h"
#include "ShortcutObjectIdolsPreset.h"
#include "ShortcutObjectItem.h"
#include "ShortcutObjectPreset.h"
#include "ShortcutSmiley.h"
#include "ShortcutSpell.h"

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