#include "NetworkTypeHandler.h"
#include "NetworkTypesIncludes.h"

NetworkTypeHandler * NetworkTypeHandler::typeHandler = nullptr;

NetworkTypeHandler::NetworkTypeHandler() {
    id_to_builder[GameServerInformations::typeId]               = make_shared<GameServerInformations>;

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

	id_to_builder[PortalInformation::typeId]	= make_shared<PortalInformation>;
	id_to_builder[TaxCollectorStaticInformations::typeId]	= make_shared<TaxCollectorStaticInformations>;
	id_to_builder[GameRolePlayNpcInformations::typeId]	= make_shared<GameRolePlayNpcInformations>;
	id_to_builder[ObjectEffectDuration::typeId]	= make_shared<ObjectEffectDuration>;
	id_to_builder[AllianceInsiderPrismInformation::typeId]	= make_shared<AllianceInsiderPrismInformation>;
	id_to_builder[ObjectEffectInteger::typeId]	= make_shared<ObjectEffectInteger>;
	id_to_builder[HouseOnMapInformations::typeId]	= make_shared<HouseOnMapInformations>;
	id_to_builder[FightTeamMemberCharacterInformations::typeId]	= make_shared<FightTeamMemberCharacterInformations>;
	id_to_builder[InteractiveElementSkill::typeId]	= make_shared<InteractiveElementSkill>;
	id_to_builder[GameRolePlayHumanoidInformations::typeId]	= make_shared<GameRolePlayHumanoidInformations>;
	id_to_builder[EntityDispositionInformations::typeId]	= make_shared<EntityDispositionInformations>;
	id_to_builder[HumanOptionTitle::typeId]	= make_shared<HumanOptionTitle>;
	id_to_builder[GameRolePlayTreasureHintInformations::typeId]	= make_shared<GameRolePlayTreasureHintInformations>;
	id_to_builder[TaxCollectorStaticExtendedInformations::typeId]	= make_shared<TaxCollectorStaticExtendedInformations>;
	id_to_builder[FightStartingPositions::typeId]	= make_shared<FightStartingPositions>;
	id_to_builder[HouseInformationsInside::typeId]	= make_shared<HouseInformationsInside>;
	id_to_builder[GroupMonsterStaticInformations::typeId]	= make_shared<GroupMonsterStaticInformations>;
	id_to_builder[ActorRestrictionsInformations::typeId]	= make_shared<ActorRestrictionsInformations>;
	id_to_builder[GameRolePlayGroupMonsterWaveInformations::typeId]	= make_shared<GameRolePlayGroupMonsterWaveInformations>;
	id_to_builder[BasicGuildInformations::typeId]	= make_shared<BasicGuildInformations>;
	id_to_builder[MapObstacle::typeId]	= make_shared<MapObstacle>;
	id_to_builder[HumanOptionOrnament::typeId]	= make_shared<HumanOptionOrnament>;
	id_to_builder[ObjectEffectLadder::typeId]	= make_shared<ObjectEffectLadder>;
	id_to_builder[GameRolePlayGroupMonsterInformations::typeId]	= make_shared<GameRolePlayGroupMonsterInformations>;
	id_to_builder[ActorAlignmentInformations::typeId]	= make_shared<ActorAlignmentInformations>;
	id_to_builder[GameContextActorPositionInformations::typeId]	= make_shared<GameContextActorPositionInformations>;
	id_to_builder[AbstractFightTeamInformations::typeId]	= make_shared<AbstractFightTeamInformations>;
	id_to_builder[ObjectEffectCreature::typeId]	= make_shared<ObjectEffectCreature>;
	id_to_builder[MonsterInGroupInformations::typeId]	= make_shared<MonsterInGroupInformations>;
	id_to_builder[ObjectEffectDice::typeId]	= make_shared<ObjectEffectDice>;
	id_to_builder[ObjectEffect::typeId]	= make_shared<ObjectEffect>;
	id_to_builder[GameContextActorInformations::typeId]	= make_shared<GameContextActorInformations>;
	id_to_builder[HumanOptionEmote::typeId]	= make_shared<HumanOptionEmote>;
	id_to_builder[HumanOptionAlliance::typeId]	= make_shared<HumanOptionAlliance>;
	id_to_builder[ObjectEffectDate::typeId]	= make_shared<ObjectEffectDate>;
	id_to_builder[ObjectItem::typeId]	= make_shared<ObjectItem>;
	id_to_builder[HouseInstanceInformations::typeId]	= make_shared<HouseInstanceInformations>;
	id_to_builder[FightTeamMemberInformations::typeId]	= make_shared<FightTeamMemberInformations>;
	id_to_builder[SubEntity::typeId]	= make_shared<SubEntity>;
	id_to_builder[PrismInformation::typeId]	= make_shared<PrismInformation>;
	id_to_builder[GroupMonsterStaticInformationsWithAlternatives::typeId]	= make_shared<GroupMonsterStaticInformationsWithAlternatives>;
	id_to_builder[BasicNamedAllianceInformations::typeId]	= make_shared<BasicNamedAllianceInformations>;
	id_to_builder[GameRolePlayPrismInformations::typeId]	= make_shared<GameRolePlayPrismInformations>;
	id_to_builder[InteractiveElementWithAgeBonus::typeId]	= make_shared<InteractiveElementWithAgeBonus>;
	id_to_builder[ObjectEffectMinMax::typeId]	= make_shared<ObjectEffectMinMax>;
	id_to_builder[GameRolePlayNamedActorInformations::typeId]	= make_shared<GameRolePlayNamedActorInformations>;
	id_to_builder[IndexedEntityLook::typeId]	= make_shared<IndexedEntityLook>;
	id_to_builder[GuildEmblem::typeId]	= make_shared<GuildEmblem>;
	id_to_builder[StatedElement::typeId]	= make_shared<StatedElement>;
	id_to_builder[IdentifiedEntityDispositionInformations::typeId]	= make_shared<IdentifiedEntityDispositionInformations>;
	id_to_builder[BasicAllianceInformations::typeId]	= make_shared<BasicAllianceInformations>;
	id_to_builder[HumanOptionGuild::typeId]	= make_shared<HumanOptionGuild>;
	id_to_builder[GameRolePlayMerchantInformations::typeId]	= make_shared<GameRolePlayMerchantInformations>;
	id_to_builder[FightCommonInformations::typeId]	= make_shared<FightCommonInformations>;
	id_to_builder[GameRolePlayNpcWithQuestInformations::typeId]	= make_shared<GameRolePlayNpcWithQuestInformations>;
	id_to_builder[GameRolePlayCharacterInformations::typeId]	= make_shared<GameRolePlayCharacterInformations>;
	id_to_builder[FightTeamInformations::typeId]	= make_shared<FightTeamInformations>;
	id_to_builder[ObjectEffectMount::typeId]	= make_shared<ObjectEffectMount>;
	id_to_builder[AllianceInformations::typeId]	= make_shared<AllianceInformations>;
	id_to_builder[HumanOptionFollowers::typeId]	= make_shared<HumanOptionFollowers>;
	id_to_builder[GameRolePlayTaxCollectorInformations::typeId]	= make_shared<GameRolePlayTaxCollectorInformations>;
	id_to_builder[InteractiveElementNamedSkill::typeId]	= make_shared<InteractiveElementNamedSkill>;
	id_to_builder[FightTeamMemberWithAllianceCharacterInformations::typeId]	= make_shared<FightTeamMemberWithAllianceCharacterInformations>;
	id_to_builder[FightAllianceTeamInformations::typeId]	= make_shared<FightAllianceTeamInformations>;
	id_to_builder[HumanOption::typeId]	= make_shared<HumanOption>;
	id_to_builder[GameRolePlayPortalInformations::typeId]	= make_shared<GameRolePlayPortalInformations>;
	id_to_builder[EntityLook::typeId]	= make_shared<EntityLook>;
	id_to_builder[ObjectEffectString::typeId]	= make_shared<ObjectEffectString>;
	id_to_builder[InteractiveElement::typeId]	= make_shared<InteractiveElement>;
	id_to_builder[AlternativeMonstersInGroupLightInformations::typeId]	= make_shared<AlternativeMonstersInGroupLightInformations>;
	id_to_builder[HumanInformations::typeId]	= make_shared<HumanInformations>;
	id_to_builder[GameRolePlayMutantInformations::typeId]	= make_shared<GameRolePlayMutantInformations>;
	id_to_builder[AbstractSocialGroupInfos::typeId]	= make_shared<AbstractSocialGroupInfos>;
	id_to_builder[FightTeamMemberTaxCollectorInformations::typeId]	= make_shared<FightTeamMemberTaxCollectorInformations>;
	id_to_builder[HouseGuildedInformations::typeId]	= make_shared<HouseGuildedInformations>;
	id_to_builder[HumanOptionSkillUse::typeId]	= make_shared<HumanOptionSkillUse>;
	id_to_builder[FightTeamMemberEntityInformation::typeId]	= make_shared<FightTeamMemberEntityInformation>;
	id_to_builder[HouseInformations::typeId]	= make_shared<HouseInformations>;
	id_to_builder[Item::typeId]	= make_shared<Item>;
	id_to_builder[GameRolePlayNpcQuestFlag::typeId]	= make_shared<GameRolePlayNpcQuestFlag>;
	id_to_builder[FightTeamMemberMonsterInformations::typeId]	= make_shared<FightTeamMemberMonsterInformations>;
	id_to_builder[GuildInformations::typeId]	= make_shared<GuildInformations>;
	id_to_builder[MonsterInGroupLightInformations::typeId]	= make_shared<MonsterInGroupLightInformations>;
	id_to_builder[AlliancePrismInformation::typeId]	= make_shared<AlliancePrismInformation>;
	id_to_builder[AccountHouseInformations::typeId]	= make_shared<AccountHouseInformations>;
	id_to_builder[GameRolePlayActorInformations::typeId]	= make_shared<GameRolePlayActorInformations>;
	id_to_builder[HumanOptionObjectUse::typeId]	= make_shared<HumanOptionObjectUse>;
	id_to_builder[FightOptionsInformations::typeId]	= make_shared<FightOptionsInformations>;
	id_to_builder[GameRolePlayMountInformations::typeId]	= make_shared<GameRolePlayMountInformations>;
	id_to_builder[HouseInformationsForGuild::typeId]	= make_shared<HouseInformationsForGuild>;
	id_to_builder[FightEntityDispositionInformations::typeId]	= make_shared<FightEntityDispositionInformations>;

    id_to_builder[ActorOrientation::typeId] = make_shared<ActorOrientation>;
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