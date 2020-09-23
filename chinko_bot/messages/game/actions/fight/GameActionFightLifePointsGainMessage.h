#ifndef GAMEACTIONFIGHTLIFEPOINTSGAINMESSAGE_MESSAGE_H
#define GAMEACTIONFIGHTLIFEPOINTSGAINMESSAGE_MESSAGE_H

#include "AbstractGameActionMessage.h"


class GameActionFightLifePointsGainMessage : public AbstractGameActionMessage {
public:
	// Constructor
	GameActionFightLifePointsGainMessage() {};
	// Copy constructor
	GameActionFightLifePointsGainMessage(const GameActionFightLifePointsGainMessage& other) = default;

	// Copy operator
	GameActionFightLifePointsGainMessage& operator=(const GameActionFightLifePointsGainMessage& other) = default;
	// Destructor
	~GameActionFightLifePointsGainMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 1531;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	double targetId = 0;
	int delta = 0;
};

#endif