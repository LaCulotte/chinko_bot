#ifndef GAMEFIGHTMONSTERINFORMATIONS_H
#define GAMEFIGHTMONSTERINFORMATIONS_H

#include "GameFightAIInformations.h"


class GameFightMonsterInformations : public GameFightAIInformations {
public:
	// Constructor
	GameFightMonsterInformations() {};
	// Copy constructor
	GameFightMonsterInformations(const GameFightMonsterInformations& other) = default;

	// Copy operator
	GameFightMonsterInformations& operator=(const GameFightMonsterInformations& other) = default;
	// Destructor
	~GameFightMonsterInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 29;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int creatureLevel = 0;
	int creatureGrade = 0;
	int creatureGenericId = 0;
};

#endif