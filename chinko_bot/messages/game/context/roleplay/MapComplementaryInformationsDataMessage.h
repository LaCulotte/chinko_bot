#ifndef MAPCOMPLEMENTARYINFORMATIONSDATAMESSAGE_MESSAGE_H
#define MAPCOMPLEMENTARYINFORMATIONSDATAMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "GameRolePlayActorInformations.h"
#include "MapObstacle.h"
#include "HouseInformations.h"
#include "FightStartingPositions.h"
#include "FightCommonInformations.h"
#include "InteractiveElement.h"
#include "StatedElement.h"

#include "NetworkTypeHandler.h"

class MapComplementaryInformationsDataMessage : public PrefixedMessage {
public:
	// Constructor
	MapComplementaryInformationsDataMessage() {};
	// Copy constructor
	MapComplementaryInformationsDataMessage(const MapComplementaryInformationsDataMessage& other) = default;

	// Copy operator
	MapComplementaryInformationsDataMessage& operator=(const MapComplementaryInformationsDataMessage& other) = default;
	// Destructor
	~MapComplementaryInformationsDataMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 5176;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<sp<GameRolePlayActorInformations>> actors;
	vector<MapObstacle> obstacles;
	int subAreaId = 0;
	double mapId = 0;
	bool hasAggressiveMonsters = false;
	vector<sp<HouseInformations>> houses;
	FightStartingPositions fightStartPositions;
	vector<FightCommonInformations> fights;
	vector<sp<InteractiveElement>> interactiveElements;
	vector<StatedElement> statedElements;
};

#endif