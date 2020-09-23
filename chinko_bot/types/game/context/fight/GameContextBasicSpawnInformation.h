#ifndef GAMECONTEXTBASICSPAWNINFORMATION_H
#define GAMECONTEXTBASICSPAWNINFORMATION_H

#include "NetworkType.h"

#include "GameContextActorPositionInformations.h"

#include "NetworkTypeHandler.h"

class GameContextBasicSpawnInformation : public NetworkType {
public:
	// Constructor
	GameContextBasicSpawnInformation() {};
	// Copy constructor
	GameContextBasicSpawnInformation(const GameContextBasicSpawnInformation& other) = default;

	// Copy operator
	GameContextBasicSpawnInformation& operator=(const GameContextBasicSpawnInformation& other) = default;
	// Destructor
	~GameContextBasicSpawnInformation() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 7069;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	sp<GameContextActorPositionInformations> informations;
	bool alive = false;
	int teamId = 2;
};

#endif