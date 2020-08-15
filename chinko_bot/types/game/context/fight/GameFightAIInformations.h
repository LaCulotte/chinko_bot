#ifndef GAMEFIGHTAIINFORMATIONS_H
#define GAMEFIGHTAIINFORMATIONS_H

#include "GameFightFighterInformations.h"


class GameFightAIInformations : public GameFightFighterInformations {
public:
	// Constructor
	GameFightAIInformations() {};
	// Copy constructor
	GameFightAIInformations(const GameFightAIInformations& other) = default;

	// Copy operator
	GameFightAIInformations& operator=(const GameFightAIInformations& other) = default;
	// Destructor
	~GameFightAIInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 151;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override { return GameFightFighterInformations::deserialize(input); };
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override { return GameFightFighterInformations::serialize(output); };

};

#endif