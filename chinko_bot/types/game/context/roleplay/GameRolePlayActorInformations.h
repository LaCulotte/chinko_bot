#ifndef GAMEROLEPLAYACTORINFORMATIONS_H
#define GAMEROLEPLAYACTORINFORMATIONS_H

#include "GameContextActorInformations.h"


class GameRolePlayActorInformations : public GameContextActorInformations {
public:
	// Constructor
	GameRolePlayActorInformations() {};
	// Copy constructor
	GameRolePlayActorInformations(const GameRolePlayActorInformations& other) = default;

	// Copy operator
	GameRolePlayActorInformations& operator=(const GameRolePlayActorInformations& other) = default;
	// Destructor
	~GameRolePlayActorInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 4806;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override { return GameContextActorInformations::deserialize(input); };
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override { return GameContextActorInformations::serialize(output); };

};

#endif