#ifndef GAMEROLEPLAYMUTANTINFORMATIONS_H
#define GAMEROLEPLAYMUTANTINFORMATIONS_H

#include "GameRolePlayHumanoidInformations.h"


class GameRolePlayMutantInformations : public GameRolePlayHumanoidInformations {
public:
	// Constructor
	GameRolePlayMutantInformations() {};
	// Copy constructor
	GameRolePlayMutantInformations(const GameRolePlayMutantInformations& other) = default;

	// Copy operator
	GameRolePlayMutantInformations& operator=(const GameRolePlayMutantInformations& other) = default;
	// Destructor
	~GameRolePlayMutantInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 860;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int powerLevel = 0;
	int monsterId = 0;
};

#endif