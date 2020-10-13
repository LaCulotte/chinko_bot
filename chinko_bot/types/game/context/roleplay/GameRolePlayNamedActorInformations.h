#ifndef GAMEROLEPLAYNAMEDACTORINFORMATIONS_H
#define GAMEROLEPLAYNAMEDACTORINFORMATIONS_H

#include "GameRolePlayActorInformations.h"


class GameRolePlayNamedActorInformations : public GameRolePlayActorInformations {
public:
	// Constructor
	GameRolePlayNamedActorInformations() {};
	// Copy constructor
	GameRolePlayNamedActorInformations(const GameRolePlayNamedActorInformations& other) = default;

	// Copy operator
	GameRolePlayNamedActorInformations& operator=(const GameRolePlayNamedActorInformations& other) = default;
	// Destructor
	~GameRolePlayNamedActorInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 2876;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	string name;
};

#endif