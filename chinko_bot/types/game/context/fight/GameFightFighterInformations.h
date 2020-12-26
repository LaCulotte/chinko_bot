#ifndef GAMEFIGHTFIGHTERINFORMATIONS_H
#define GAMEFIGHTFIGHTERINFORMATIONS_H

#include "GameContextActorInformations.h"

#include "GameFightMinimalStats.h"
#include "GameContextBasicSpawnInformation.h"

#include "NetworkTypeHandler.h"

class GameFightFighterInformations : public GameContextActorInformations {
public:
	// Constructor
	GameFightFighterInformations() {};
	// Copy constructor
	GameFightFighterInformations(const GameFightFighterInformations& other) = default;

	// Copy operator
	GameFightFighterInformations& operator=(const GameFightFighterInformations& other) = default;
	// Destructor
	~GameFightFighterInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 6298;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<int> previousPositions;
	sp<GameFightMinimalStats> stats;
	int wave = 0;
	GameContextBasicSpawnInformation spawnInfo;
};

#endif