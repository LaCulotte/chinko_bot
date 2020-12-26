#ifndef GAMEACTIONFIGHTDEATHMESSAGE_MESSAGE_H
#define GAMEACTIONFIGHTDEATHMESSAGE_MESSAGE_H

#include "AbstractGameActionMessage.h"


class GameActionFightDeathMessage : public AbstractGameActionMessage {
public:
	// Constructor
	GameActionFightDeathMessage() {};
	// Copy constructor
	GameActionFightDeathMessage(const GameActionFightDeathMessage& other) = default;

	// Copy operator
	GameActionFightDeathMessage& operator=(const GameActionFightDeathMessage& other) = default;
	// Destructor
	~GameActionFightDeathMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 7906;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	double targetId = 0;
};

#endif