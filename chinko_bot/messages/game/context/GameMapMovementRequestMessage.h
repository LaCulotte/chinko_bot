#ifndef GAMEMAPMOVEMENTREQUESTMESSAGE_MESSAGE_H
#define GAMEMAPMOVEMENTREQUESTMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class GameMapMovementRequestMessage : public PrefixedMessage {
public:
	// Constructor
	GameMapMovementRequestMessage() {};
	// Copy constructor
	GameMapMovementRequestMessage(const GameMapMovementRequestMessage& other) = default;

	// Copy operator
	GameMapMovementRequestMessage& operator=(const GameMapMovementRequestMessage& other) = default;
	// Destructor
	~GameMapMovementRequestMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 3376;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	double mapId = 0;
	vector<int> keyMovements;
};

#endif