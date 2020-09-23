#ifndef GAMEFIGHTTURNSTARTMESSAGE_MESSAGE_H
#define GAMEFIGHTTURNSTARTMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class GameFightTurnStartMessage : public PrefixedMessage {
public:
	// Constructor
	GameFightTurnStartMessage() {};
	// Copy constructor
	GameFightTurnStartMessage(const GameFightTurnStartMessage& other) = default;

	// Copy operator
	GameFightTurnStartMessage& operator=(const GameFightTurnStartMessage& other) = default;
	// Destructor
	~GameFightTurnStartMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 7110;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int waitTime = 0;
	double id = 0;
};

#endif