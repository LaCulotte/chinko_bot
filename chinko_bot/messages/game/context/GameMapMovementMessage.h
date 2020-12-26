#ifndef GAMEMAPMOVEMENTMESSAGE_MESSAGE_H
#define GAMEMAPMOVEMENTMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class GameMapMovementMessage : public PrefixedMessage {
public:
	// Constructor
	GameMapMovementMessage() {};
	// Copy constructor
	GameMapMovementMessage(const GameMapMovementMessage& other) = default;

	// Copy operator
	GameMapMovementMessage& operator=(const GameMapMovementMessage& other) = default;
	// Destructor
	~GameMapMovementMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 9211;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	double actorId = 0;
	int forcedDirection = 0;
	vector<int> keyMovements;
};

#endif