#ifndef GAMEACTIONFIGHTLIFEANDSHIELDPOINTSLOSTMESSAGE_MESSAGE_H
#define GAMEACTIONFIGHTLIFEANDSHIELDPOINTSLOSTMESSAGE_MESSAGE_H

#include "GameActionFightLifePointsLostMessage.h"


class GameActionFightLifeAndShieldPointsLostMessage : public GameActionFightLifePointsLostMessage {
public:
	// Constructor
	GameActionFightLifeAndShieldPointsLostMessage() {};
	// Copy constructor
	GameActionFightLifeAndShieldPointsLostMessage(const GameActionFightLifeAndShieldPointsLostMessage& other) = default;

	// Copy operator
	GameActionFightLifeAndShieldPointsLostMessage& operator=(const GameActionFightLifeAndShieldPointsLostMessage& other) = default;
	// Destructor
	~GameActionFightLifeAndShieldPointsLostMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 1903;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int shieldLoss = 0;
};

#endif