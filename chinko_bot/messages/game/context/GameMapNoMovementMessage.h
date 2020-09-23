#ifndef GAMEMAPNOMOVEMENTMESSAGE_MESSAGE_H
#define GAMEMAPNOMOVEMENTMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class GameMapNoMovementMessage : public PrefixedMessage {
public:
	// Constructor
	GameMapNoMovementMessage() {};
	// Copy constructor
	GameMapNoMovementMessage(const GameMapNoMovementMessage& other) = default;

	// Copy operator
	GameMapNoMovementMessage& operator=(const GameMapNoMovementMessage& other) = default;
	// Destructor
	~GameMapNoMovementMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 5382;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int cellY = 0;
	int cellX = 0;
};

#endif