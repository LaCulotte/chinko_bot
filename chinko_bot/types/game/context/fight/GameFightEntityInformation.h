#ifndef GAMEFIGHTENTITYINFORMATION_H
#define GAMEFIGHTENTITYINFORMATION_H

#include "GameFightFighterInformations.h"


class GameFightEntityInformation : public GameFightFighterInformations {
public:
	// Constructor
	GameFightEntityInformation() {};
	// Copy constructor
	GameFightEntityInformation(const GameFightEntityInformation& other) = default;

	// Copy operator
	GameFightEntityInformation& operator=(const GameFightEntityInformation& other) = default;
	// Destructor
	~GameFightEntityInformation() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 9631;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	double masterId = 0;
	int level = 0;
	int entityModelId = 0;
};

#endif