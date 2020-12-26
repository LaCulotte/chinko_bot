#ifndef GAMEROLEPLAYGROUPMONSTERINFORMATIONS_H
#define GAMEROLEPLAYGROUPMONSTERINFORMATIONS_H

#include "GameRolePlayActorInformations.h"

#include "GroupMonsterStaticInformations.h"

#include "NetworkTypeHandler.h"

class GameRolePlayGroupMonsterInformations : public GameRolePlayActorInformations {
public:
	// Constructor
	GameRolePlayGroupMonsterInformations() {};
	// Copy constructor
	GameRolePlayGroupMonsterInformations(const GameRolePlayGroupMonsterInformations& other) = default;

	// Copy operator
	GameRolePlayGroupMonsterInformations& operator=(const GameRolePlayGroupMonsterInformations& other) = default;
	// Destructor
	~GameRolePlayGroupMonsterInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 9292;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	bool hasAVARewardToken = false;
	bool hasHardcoreDrop = false;
	int alignmentSide = 0;
	bool keyRingBonus = false;
	int lootShare = 0;
	sp<GroupMonsterStaticInformations> staticInfos;
};

#endif