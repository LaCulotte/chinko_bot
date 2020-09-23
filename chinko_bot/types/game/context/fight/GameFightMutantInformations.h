#ifndef GAMEFIGHTMUTANTINFORMATIONS_H
#define GAMEFIGHTMUTANTINFORMATIONS_H

#include "GameFightFighterNamedInformations.h"


class GameFightMutantInformations : public GameFightFighterNamedInformations {
public:
	// Constructor
	GameFightMutantInformations() {};
	// Copy constructor
	GameFightMutantInformations(const GameFightMutantInformations& other) = default;

	// Copy operator
	GameFightMutantInformations& operator=(const GameFightMutantInformations& other) = default;
	// Destructor
	~GameFightMutantInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 4633;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int powerLevel = 0;
};

#endif