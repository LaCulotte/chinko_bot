#ifndef GAMEFIGHTNEWROUNDMESSAGE_MESSAGE_H
#define GAMEFIGHTNEWROUNDMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class GameFightNewRoundMessage : public PrefixedMessage {
public:
	// Constructor
	GameFightNewRoundMessage() {};
	// Copy constructor
	GameFightNewRoundMessage(const GameFightNewRoundMessage& other) = default;

	// Copy operator
	GameFightNewRoundMessage& operator=(const GameFightNewRoundMessage& other) = default;
	// Destructor
	~GameFightNewRoundMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 6998;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int roundNumber = 0;
};

#endif