#ifndef GAMEACTIONACKNOWLEDGEMENTMESSAGE_MESSAGE_H
#define GAMEACTIONACKNOWLEDGEMENTMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class GameActionAcknowledgementMessage : public PrefixedMessage {
public:
	// Constructor
	GameActionAcknowledgementMessage() {};
	// Copy constructor
	GameActionAcknowledgementMessage(const GameActionAcknowledgementMessage& other) = default;

	// Copy operator
	GameActionAcknowledgementMessage& operator=(const GameActionAcknowledgementMessage& other) = default;
	// Destructor
	~GameActionAcknowledgementMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 9063;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int actionId = 0;
	bool valid = false;
};

#endif