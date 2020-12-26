#ifndef GAMEFIGHTSTARTMESSAGE_MESSAGE_H
#define GAMEFIGHTSTARTMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "Idol.h"

class GameFightStartMessage : public PrefixedMessage {
public:
	// Constructor
	GameFightStartMessage() {};
	// Copy constructor
	GameFightStartMessage(const GameFightStartMessage& other) = default;

	// Copy operator
	GameFightStartMessage& operator=(const GameFightStartMessage& other) = default;
	// Destructor
	~GameFightStartMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 9802;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<Idol> idols;
};

#endif