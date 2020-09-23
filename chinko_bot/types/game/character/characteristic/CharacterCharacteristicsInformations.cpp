#include "CharacterCharacteristicsInformations.h"

bool CharacterCharacteristicsInformations::serialize(sp<MessageDataBuffer> output) {
	output->writeVarInt64(experience);
	output->writeVarInt64(experienceLevelFloor);
	output->writeVarInt64(experienceNextLevelFloor);
	output->writeVarInt64(experienceBonusLimit);
	output->writeVarInt64(kamas);
	output->writeVarShort(statsPoints);
	output->writeVarShort(additionnalPoints);
	output->writeVarShort(spellsPoints);
	alignmentInfos.serialize(output);
	output->writeVarInt(lifePoints);
	output->writeVarInt(maxLifePoints);
	output->writeVarShort(energyPoints);
	output->writeVarShort(maxEnergyPoints);
	output->writeVarShort(actionPointsCurrent);
	output->writeVarShort(movementPointsCurrent);
	initiative.serialize(output);
	prospecting.serialize(output);
	actionPoints.serialize(output);
	movementPoints.serialize(output);
	strength.serialize(output);
	vitality.serialize(output);
	wisdom.serialize(output);
	chance.serialize(output);
	agility.serialize(output);
	intelligence.serialize(output);
	range.serialize(output);
	summonableCreaturesBoost.serialize(output);
	reflect.serialize(output);
	criticalHit.serialize(output);
	output->writeVarShort(criticalHitWeapon);
	criticalMiss.serialize(output);
	healBonus.serialize(output);
	allDamagesBonus.serialize(output);
	weaponDamagesBonusPercent.serialize(output);
	damagesBonusPercent.serialize(output);
	trapBonus.serialize(output);
	trapBonusPercent.serialize(output);
	glyphBonusPercent.serialize(output);
	runeBonusPercent.serialize(output);
	permanentDamagePercent.serialize(output);
	tackleBlock.serialize(output);
	tackleEvade.serialize(output);
	PAAttack.serialize(output);
	PMAttack.serialize(output);
	pushDamageBonus.serialize(output);
	criticalDamageBonus.serialize(output);
	neutralDamageBonus.serialize(output);
	earthDamageBonus.serialize(output);
	waterDamageBonus.serialize(output);
	airDamageBonus.serialize(output);
	fireDamageBonus.serialize(output);
	dodgePALostProbability.serialize(output);
	dodgePMLostProbability.serialize(output);
	neutralElementResistPercent.serialize(output);
	earthElementResistPercent.serialize(output);
	waterElementResistPercent.serialize(output);
	airElementResistPercent.serialize(output);
	fireElementResistPercent.serialize(output);
	neutralElementReduction.serialize(output);
	earthElementReduction.serialize(output);
	waterElementReduction.serialize(output);
	airElementReduction.serialize(output);
	fireElementReduction.serialize(output);
	pushDamageReduction.serialize(output);
	criticalDamageReduction.serialize(output);
	pvpNeutralElementResistPercent.serialize(output);
	pvpEarthElementResistPercent.serialize(output);
	pvpWaterElementResistPercent.serialize(output);
	pvpAirElementResistPercent.serialize(output);
	pvpFireElementResistPercent.serialize(output);
	pvpNeutralElementReduction.serialize(output);
	pvpEarthElementReduction.serialize(output);
	pvpWaterElementReduction.serialize(output);
	pvpAirElementReduction.serialize(output);
	pvpFireElementReduction.serialize(output);
	meleeDamageDonePercent.serialize(output);
	meleeDamageReceivedPercent.serialize(output);
	rangedDamageDonePercent.serialize(output);
	rangedDamageReceivedPercent.serialize(output);
	weaponDamageDonePercent.serialize(output);
	weaponDamageReceivedPercent.serialize(output);
	spellDamageDonePercent.serialize(output);
	spellDamageReceivedPercent.serialize(output);
	output->writeShort(spellModifications.size());
	for(int i = 0; i < spellModifications.size(); i++) {
		spellModifications[i].serialize(output);
	}
	output->writeInt(probationTime);

    return true;
}

bool CharacterCharacteristicsInformations::deserialize(sp<MessageDataBuffer> input) {
	experience = input->readVarInt64();
	experienceLevelFloor = input->readVarInt64();
	experienceNextLevelFloor = input->readVarInt64();
	experienceBonusLimit = input->readVarInt64();
	kamas = input->readVarInt64();
	statsPoints = input->readVarShort();
	additionnalPoints = input->readVarShort();
	spellsPoints = input->readVarShort();
	if(!alignmentInfos.deserialize(input))
		return false;
	lifePoints = input->readVarInt();
	maxLifePoints = input->readVarInt();
	energyPoints = input->readVarShort();
	maxEnergyPoints = input->readVarShort();
	actionPointsCurrent = input->readVarShort();
	movementPointsCurrent = input->readVarShort();
	if(!initiative.deserialize(input))
		return false;
	if(!prospecting.deserialize(input))
		return false;
	if(!actionPoints.deserialize(input))
		return false;
	if(!movementPoints.deserialize(input))
		return false;
	if(!strength.deserialize(input))
		return false;
	if(!vitality.deserialize(input))
		return false;
	if(!wisdom.deserialize(input))
		return false;
	if(!chance.deserialize(input))
		return false;
	if(!agility.deserialize(input))
		return false;
	if(!intelligence.deserialize(input))
		return false;
	if(!range.deserialize(input))
		return false;
	if(!summonableCreaturesBoost.deserialize(input))
		return false;
	if(!reflect.deserialize(input))
		return false;
	if(!criticalHit.deserialize(input))
		return false;
	criticalHitWeapon = input->readVarShort();
	if(!criticalMiss.deserialize(input))
		return false;
	if(!healBonus.deserialize(input))
		return false;
	if(!allDamagesBonus.deserialize(input))
		return false;
	if(!weaponDamagesBonusPercent.deserialize(input))
		return false;
	if(!damagesBonusPercent.deserialize(input))
		return false;
	if(!trapBonus.deserialize(input))
		return false;
	if(!trapBonusPercent.deserialize(input))
		return false;
	if(!glyphBonusPercent.deserialize(input))
		return false;
	if(!runeBonusPercent.deserialize(input))
		return false;
	if(!permanentDamagePercent.deserialize(input))
		return false;
	if(!tackleBlock.deserialize(input))
		return false;
	if(!tackleEvade.deserialize(input))
		return false;
	if(!PAAttack.deserialize(input))
		return false;
	if(!PMAttack.deserialize(input))
		return false;
	if(!pushDamageBonus.deserialize(input))
		return false;
	if(!criticalDamageBonus.deserialize(input))
		return false;
	if(!neutralDamageBonus.deserialize(input))
		return false;
	if(!earthDamageBonus.deserialize(input))
		return false;
	if(!waterDamageBonus.deserialize(input))
		return false;
	if(!airDamageBonus.deserialize(input))
		return false;
	if(!fireDamageBonus.deserialize(input))
		return false;
	if(!dodgePALostProbability.deserialize(input))
		return false;
	if(!dodgePMLostProbability.deserialize(input))
		return false;
	if(!neutralElementResistPercent.deserialize(input))
		return false;
	if(!earthElementResistPercent.deserialize(input))
		return false;
	if(!waterElementResistPercent.deserialize(input))
		return false;
	if(!airElementResistPercent.deserialize(input))
		return false;
	if(!fireElementResistPercent.deserialize(input))
		return false;
	if(!neutralElementReduction.deserialize(input))
		return false;
	if(!earthElementReduction.deserialize(input))
		return false;
	if(!waterElementReduction.deserialize(input))
		return false;
	if(!airElementReduction.deserialize(input))
		return false;
	if(!fireElementReduction.deserialize(input))
		return false;
	if(!pushDamageReduction.deserialize(input))
		return false;
	if(!criticalDamageReduction.deserialize(input))
		return false;
	if(!pvpNeutralElementResistPercent.deserialize(input))
		return false;
	if(!pvpEarthElementResistPercent.deserialize(input))
		return false;
	if(!pvpWaterElementResistPercent.deserialize(input))
		return false;
	if(!pvpAirElementResistPercent.deserialize(input))
		return false;
	if(!pvpFireElementResistPercent.deserialize(input))
		return false;
	if(!pvpNeutralElementReduction.deserialize(input))
		return false;
	if(!pvpEarthElementReduction.deserialize(input))
		return false;
	if(!pvpWaterElementReduction.deserialize(input))
		return false;
	if(!pvpAirElementReduction.deserialize(input))
		return false;
	if(!pvpFireElementReduction.deserialize(input))
		return false;
	if(!meleeDamageDonePercent.deserialize(input))
		return false;
	if(!meleeDamageReceivedPercent.deserialize(input))
		return false;
	if(!rangedDamageDonePercent.deserialize(input))
		return false;
	if(!rangedDamageReceivedPercent.deserialize(input))
		return false;
	if(!weaponDamageDonePercent.deserialize(input))
		return false;
	if(!weaponDamageReceivedPercent.deserialize(input))
		return false;
	if(!spellDamageDonePercent.deserialize(input))
		return false;
	if(!spellDamageReceivedPercent.deserialize(input))
		return false;
	int spellModifications_size = input->readShort();
	for(int i = 0; i < spellModifications_size; i++) {
		CharacterSpellModification spellModification;

		if(!spellModification.deserialize(input))
			return false;
		spellModifications.push_back(spellModification);
	}
	probationTime = input->readInt();

    return true;
}
