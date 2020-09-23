#ifndef GAMEACTIONFIGHTKILLMESSAGE_MESSAGE_H
#define GAMEACTIONFIGHTKILLMESSAGE_MESSAGE_H

#include "AbstractGameActionMessage.h"


class GameActionFightKillMessage : public AbstractGameActionMessage {
public:
	// Constructor
	GameActionFightKillMessage() {};
	// Copy constructor
	GameActionFightKillMessage(const GameActionFightKillMessage& other) = default;

	// Copy operator
	GameActionFightKillMessage& operator=(const GameActionFightKillMessage& other) = default;
	// Destructor
	~GameActionFightKillMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 8275;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	double targetId = 0;
};

#endif