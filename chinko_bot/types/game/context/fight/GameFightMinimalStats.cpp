#include "GameFightMinimalStats.h"

bool GameFightMinimalStats::serialize(sp<MessageDataBuffer> output) {
	output->writeVarInt(lifePoints);
	output->writeVarInt(maxLifePoints);
	output->writeVarInt(baseMaxLifePoints);
	output->writeVarInt(permanentDamagePercent);
	output->writeVarInt(shieldPoints);
	output->writeVarShort(actionPoints);
	output->writeVarShort(maxActionPoints);
	output->writeVarShort(movementPoints);
	output->writeVarShort(maxMovementPoints);
	output->writeDouble(summoner);
	output->writeBool(summoned);
	output->writeVarShort(neutralElementResistPercent);
	output->writeVarShort(earthElementResistPercent);
	output->writeVarShort(waterElementResistPercent);
	output->writeVarShort(airElementResistPercent);
	output->writeVarShort(fireElementResistPercent);
	output->writeVarShort(neutralElementReduction);
	output->writeVarShort(earthElementReduction);
	output->writeVarShort(waterElementReduction);
	output->writeVarShort(airElementReduction);
	output->writeVarShort(fireElementReduction);
	output->writeVarShort(criticalDamageFixedResist);
	output->writeVarShort(pushDamageFixedResist);
	output->writeVarShort(pvpNeutralElementResistPercent);
	output->writeVarShort(pvpEarthElementResistPercent);
	output->writeVarShort(pvpWaterElementResistPercent);
	output->writeVarShort(pvpAirElementResistPercent);
	output->writeVarShort(pvpFireElementResistPercent);
	output->writeVarShort(pvpNeutralElementReduction);
	output->writeVarShort(pvpEarthElementReduction);
	output->writeVarShort(pvpWaterElementReduction);
	output->writeVarShort(pvpAirElementReduction);
	output->writeVarShort(pvpFireElementReduction);
	output->writeVarShort(dodgePALostProbability);
	output->writeVarShort(dodgePMLostProbability);
	output->writeVarShort(tackleBlock);
	output->writeVarShort(tackleEvade);
	output->writeVarShort(fixedDamageReflection);
	output->writeByte(invisibilityState);
	output->writeVarShort(meleeDamageReceivedPercent);
	output->writeVarShort(rangedDamageReceivedPercent);
	output->writeVarShort(weaponDamageReceivedPercent);
	output->writeVarShort(spellDamageReceivedPercent);

    return true;
}

bool GameFightMinimalStats::deserialize(sp<MessageDataBuffer> input) {
	lifePoints = input->readVarInt();
	maxLifePoints = input->readVarInt();
	baseMaxLifePoints = input->readVarInt();
	permanentDamagePercent = input->readVarInt();
	shieldPoints = input->readVarInt();
	actionPoints = input->readVarShort();
	maxActionPoints = input->readVarShort();
	movementPoints = input->readVarShort();
	maxMovementPoints = input->readVarShort();
	summoner = input->readDouble();
	summoned = input->readBool();
	neutralElementResistPercent = input->readVarShort();
	earthElementResistPercent = input->readVarShort();
	waterElementResistPercent = input->readVarShort();
	airElementResistPercent = input->readVarShort();
	fireElementResistPercent = input->readVarShort();
	neutralElementReduction = input->readVarShort();
	earthElementReduction = input->readVarShort();
	waterElementReduction = input->readVarShort();
	airElementReduction = input->readVarShort();
	fireElementReduction = input->readVarShort();
	criticalDamageFixedResist = input->readVarShort();
	pushDamageFixedResist = input->readVarShort();
	pvpNeutralElementResistPercent = input->readVarShort();
	pvpEarthElementResistPercent = input->readVarShort();
	pvpWaterElementResistPercent = input->readVarShort();
	pvpAirElementResistPercent = input->readVarShort();
	pvpFireElementResistPercent = input->readVarShort();
	pvpNeutralElementReduction = input->readVarShort();
	pvpEarthElementReduction = input->readVarShort();
	pvpWaterElementReduction = input->readVarShort();
	pvpAirElementReduction = input->readVarShort();
	pvpFireElementReduction = input->readVarShort();
	dodgePALostProbability = input->readVarShort();
	dodgePMLostProbability = input->readVarShort();
	tackleBlock = input->readVarShort();
	tackleEvade = input->readVarShort();
	fixedDamageReflection = input->readVarShort();
	invisibilityState = input->readByte();
	meleeDamageReceivedPercent = input->readVarShort();
	rangedDamageReceivedPercent = input->readVarShort();
	weaponDamageReceivedPercent = input->readVarShort();
	spellDamageReceivedPercent = input->readVarShort();

    return true;
}
