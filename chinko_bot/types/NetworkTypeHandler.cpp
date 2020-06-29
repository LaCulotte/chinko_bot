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

    id_to_builder[Item::typeId]                                 = make_shared<Item>;
    id_to_builder[ObjectItem::typeId]                           = make_shared<ObjectItem>;
    id_to_builder[SpellItem::typeId]                            = make_shared<SpellItem>;
    id_to_builder[ObjectEffect::typeId]                         = make_shared<ObjectEffect>;
    id_to_builder[ObjectEffectCreature::typeId]                 = make_shared<ObjectEffectCreature>;
    id_to_builder[ObjectEffectDate::typeId]                     = make_shared<ObjectEffectDate>;
    id_to_builder[ObjectEffectDice::typeId]                     = make_shared<ObjectEffectDice>;
    id_to_builder[ObjectEffectInteger::typeId]                  = make_shared<ObjectEffectInteger>;
    id_to_builder[ObjectEffectLadder::typeId]                   = make_shared<ObjectEffectLadder>;
    id_to_builder[ObjectEffectMinMax::typeId]                   = make_shared<ObjectEffectMinMax>;
    id_to_builder[ObjectEffectMount::typeId]                    = make_shared<ObjectEffectMount>;
    id_to_builder[ObjectEffectString::typeId]                   = make_shared<ObjectEffectString>;

    id_to_builder[Shortcut::typeId]                             = make_shared<Shortcut>;
    id_to_builder[ShortcutEmote::typeId]                        = make_shared<ShortcutEmote>;
    id_to_builder[ShortcutObject::typeId]                       = make_shared<ShortcutObject>;
    id_to_builder[ShortcutObjectIdolsPreset::typeId]            = make_shared<ShortcutObjectIdolsPreset>;
    id_to_builder[ShortcutObjectItem::typeId]                   = make_shared<ShortcutObjectItem>;
    id_to_builder[ShortcutObjectPreset::typeId]                 = make_shared<ShortcutObjectPreset>;
    id_to_builder[ShortcutSmiley::typeId]                       = make_shared<ShortcutSmiley>;
    id_to_builder[ShortcutSpell::typeId]                        = make_shared<ShortcutSpell>;
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