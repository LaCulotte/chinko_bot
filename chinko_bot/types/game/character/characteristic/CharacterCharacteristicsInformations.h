#ifndef CHARACTERCHARACTERISTICSINFORMATIONS_H
#define CHARACTERCHARACTERISTICSINFORMATIONS_H

#include "NetworkType.h"

#include "CharacterBaseCharacteristic.h"
#include "CharacterSpellModification.h"
#include "ActorExtendedAlignmentInformations.h"

class CharacterCharacteristicsInformations : public NetworkType {
public:
	// Constructor
	CharacterCharacteristicsInformations() {};
	// Copy constructor
	CharacterCharacteristicsInformations(const CharacterCharacteristicsInformations& other) = default;

	// Copy operator
	CharacterCharacteristicsInformations& operator=(const CharacterCharacteristicsInformations& other) = default;
	// Destructor
	~CharacterCharacteristicsInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 322;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	CharacterBaseCharacteristic neutralElementReduction;
	CharacterBaseCharacteristic fireElementResistPercent;
	CharacterBaseCharacteristic dodgePMLostProbability;
	vector<CharacterSpellModification> spellModifications;
	CharacterBaseCharacteristic pvpFireElementReduction;
	int probationTime = 0;
	CharacterBaseCharacteristic waterDamageBonus;
	CharacterBaseCharacteristic initiative;
	CharacterBaseCharacteristic pushDamageBonus;
	CharacterBaseCharacteristic permanentDamagePercent;
	CharacterBaseCharacteristic PMAttack;
	CharacterBaseCharacteristic tackleEvade;
	int actionPointsCurrent = 0;
	CharacterBaseCharacteristic trapBonusPercent;
	CharacterBaseCharacteristic trapBonus;
	CharacterBaseCharacteristic earthDamageBonus;
	CharacterBaseCharacteristic runeBonusPercent;
	CharacterBaseCharacteristic intelligence;
	ActorExtendedAlignmentInformations alignmentInfos;
	uint64_t kamas = 0;
	uint64_t experienceBonusLimit = 0;
	int criticalHitWeapon = 0;
	uint64_t experienceNextLevelFloor = 0;
	CharacterBaseCharacteristic criticalDamageBonus;
	CharacterBaseCharacteristic actionPoints;
	uint64_t experienceLevelFloor = 0;
	int maxEnergyPoints = 0;
	CharacterBaseCharacteristic neutralDamageBonus;
	CharacterBaseCharacteristic range;
	CharacterBaseCharacteristic neutralElementResistPercent;
	CharacterBaseCharacteristic vitality;
	CharacterBaseCharacteristic PAAttack;
	CharacterBaseCharacteristic pvpNeutralElementReduction;
	int movementPointsCurrent = 0;
	CharacterBaseCharacteristic airElementResistPercent;
	CharacterBaseCharacteristic summonableCreaturesBoost;
	CharacterBaseCharacteristic agility;
	CharacterBaseCharacteristic weaponDamagesBonusPercent;
	CharacterBaseCharacteristic movementPoints;
	CharacterBaseCharacteristic chance;
	CharacterBaseCharacteristic strength;
	CharacterBaseCharacteristic criticalHit;
	CharacterBaseCharacteristic fireDamageBonus;
	CharacterBaseCharacteristic criticalMiss;
	CharacterBaseCharacteristic damagesBonusPercent;
	int spellsPoints = 0;
	CharacterBaseCharacteristic spellDamageReceivedPercent;
	CharacterBaseCharacteristic prospecting;
	CharacterBaseCharacteristic wisdom;
	uint64_t experience = 0;
	CharacterBaseCharacteristic glyphBonusPercent;
	CharacterBaseCharacteristic reflect;
	int additionnalPoints = 0;
	CharacterBaseCharacteristic earthElementResistPercent;
	CharacterBaseCharacteristic airDamageBonus;
	CharacterBaseCharacteristic earthElementReduction;
	CharacterBaseCharacteristic waterElementReduction;
	CharacterBaseCharacteristic pvpFireElementResistPercent;
	CharacterBaseCharacteristic allDamagesBonus;
	CharacterBaseCharacteristic airElementReduction;
	int maxLifePoints = 0;
	CharacterBaseCharacteristic fireElementReduction;
	CharacterBaseCharacteristic criticalDamageReduction;
	CharacterBaseCharacteristic pvpNeutralElementResistPercent;
	CharacterBaseCharacteristic tackleBlock;
	CharacterBaseCharacteristic pvpAirElementResistPercent;
	CharacterBaseCharacteristic pvpEarthElementReduction;
	CharacterBaseCharacteristic pvpWaterElementReduction;
	CharacterBaseCharacteristic dodgePALostProbability;
	CharacterBaseCharacteristic pvpAirElementReduction;
	CharacterBaseCharacteristic pvpWaterElementResistPercent;
	CharacterBaseCharacteristic weaponDamageReceivedPercent;
	CharacterBaseCharacteristic healBonus;
	int statsPoints = 0;
	CharacterBaseCharacteristic meleeDamageDonePercent;
	CharacterBaseCharacteristic pvpEarthElementResistPercent;
	CharacterBaseCharacteristic meleeDamageReceivedPercent;
	CharacterBaseCharacteristic rangedDamageDonePercent;
	CharacterBaseCharacteristic weaponDamageDonePercent;
	int energyPoints = 0;
	CharacterBaseCharacteristic spellDamageDonePercent;
	CharacterBaseCharacteristic pushDamageReduction;
	CharacterBaseCharacteristic waterElementResistPercent;
	CharacterBaseCharacteristic rangedDamageReceivedPercent;
	int lifePoints = 0;
};

#endif