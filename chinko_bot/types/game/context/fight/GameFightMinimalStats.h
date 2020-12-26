#ifndef GAMEFIGHTMINIMALSTATS_H
#define GAMEFIGHTMINIMALSTATS_H

#include "NetworkType.h"


class GameFightMinimalStats : public NetworkType {
public:
	// Constructor
	GameFightMinimalStats() {};
	// Copy constructor
	GameFightMinimalStats(const GameFightMinimalStats& other) = default;

	// Copy operator
	GameFightMinimalStats& operator=(const GameFightMinimalStats& other) = default;
	// Destructor
	~GameFightMinimalStats() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 7930;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int weaponDamageReceivedPercent = 0;
	int rangedDamageReceivedPercent = 0;
	int meleeDamageReceivedPercent = 0;
	int fixedDamageReflection = 0;
	int tackleBlock = 0;
	int dodgePMLostProbability = 0;
	int pvpAirElementReduction = 0;
	int pvpEarthElementReduction = 0;
	int neutralElementReduction = 0;
	bool summoned = false;
	int maxActionPoints = 0;
	int shieldPoints = 0;
	int pvpEarthElementResistPercent = 0;
	double summoner = 0;
	int lifePoints = 0;
	int invisibilityState = 0;
	int earthElementReduction = 0;
	int neutralElementResistPercent = 0;
	int actionPoints = 0;
	int baseMaxLifePoints = 0;
	int earthElementResistPercent = 0;
	int tackleEvade = 0;
	int pvpAirElementResistPercent = 0;
	int maxMovementPoints = 0;
	int movementPoints = 0;
	int airElementResistPercent = 0;
	int dodgePALostProbability = 0;
	int airElementReduction = 0;
	int maxLifePoints = 0;
	int fireElementReduction = 0;
	int fireElementResistPercent = 0;
	int pvpWaterElementResistPercent = 0;
	int spellDamageReceivedPercent = 0;
	int criticalDamageFixedResist = 0;
	int pvpWaterElementReduction = 0;
	int waterElementResistPercent = 0;
	int waterElementReduction = 0;
	int pushDamageFixedResist = 0;
	int pvpFireElementReduction = 0;
	int pvpNeutralElementResistPercent = 0;
	int permanentDamagePercent = 0;
	int pvpFireElementResistPercent = 0;
	int pvpNeutralElementReduction = 0;
};

#endif