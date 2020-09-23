#ifndef GAMEFIGHTSTARTINGMESSAGE_MESSAGE_H
#define GAMEFIGHTSTARTINGMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class GameFightStartingMessage : public PrefixedMessage {
public:
	// Constructor
	GameFightStartingMessage() {};
	// Copy constructor
	GameFightStartingMessage(const GameFightStartingMessage& other) = default;

	// Copy operator
	GameFightStartingMessage& operator=(const GameFightStartingMessage& other) = default;
	// Destructor
	~GameFightStartingMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 3960;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	double attackerId = 0;
	int fightId = 0;
	int fightType = 0;
	double defenderId = 0;
};

#endif