#ifndef GAMEACTIONFIGHTLIFEPOINTSLOSTMESSAGE_MESSAGE_H
#define GAMEACTIONFIGHTLIFEPOINTSLOSTMESSAGE_MESSAGE_H

#include "AbstractGameActionMessage.h"


class GameActionFightLifePointsLostMessage : public AbstractGameActionMessage {
public:
	// Constructor
	GameActionFightLifePointsLostMessage() {};
	// Copy constructor
	GameActionFightLifePointsLostMessage(const GameActionFightLifePointsLostMessage& other) = default;

	// Copy operator
	GameActionFightLifePointsLostMessage& operator=(const GameActionFightLifePointsLostMessage& other) = default;
	// Destructor
	~GameActionFightLifePointsLostMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 4391;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int permanentDamages = 0;
	int elementId = 0;
	int loss = 0;
	double targetId = 0;
};

#endif