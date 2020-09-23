#ifndef GAMECONTEXTACTORINFORMATIONS_H
#define GAMECONTEXTACTORINFORMATIONS_H

#include "GameContextActorPositionInformations.h"

#include "EntityLook.h"

class GameContextActorInformations : public GameContextActorPositionInformations {
public:
	// Constructor
	GameContextActorInformations() {};
	// Copy constructor
	GameContextActorInformations(const GameContextActorInformations& other) = default;

	// Copy operator
	GameContextActorInformations& operator=(const GameContextActorInformations& other) = default;
	// Destructor
	~GameContextActorInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 424;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	EntityLook look;
};

#endif