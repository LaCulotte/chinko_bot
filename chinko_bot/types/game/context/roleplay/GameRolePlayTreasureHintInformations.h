#ifndef GAMEROLEPLAYTREASUREHINTINFORMATIONS_H
#define GAMEROLEPLAYTREASUREHINTINFORMATIONS_H

#include "GameRolePlayActorInformations.h"


class GameRolePlayTreasureHintInformations : public GameRolePlayActorInformations {
public:
	// Constructor
	GameRolePlayTreasureHintInformations() {};
	// Copy constructor
	GameRolePlayTreasureHintInformations(const GameRolePlayTreasureHintInformations& other) = default;

	// Copy operator
	GameRolePlayTreasureHintInformations& operator=(const GameRolePlayTreasureHintInformations& other) = default;
	// Destructor
	~GameRolePlayTreasureHintInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 8498;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int npcId = 0;
};

#endif