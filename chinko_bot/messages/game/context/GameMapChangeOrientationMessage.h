#ifndef GAMEMAPCHANGEORIENTATIONMESSAGE_MESSAGE_H
#define GAMEMAPCHANGEORIENTATIONMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "ActorOrientation.h"

class GameMapChangeOrientationMessage : public PrefixedMessage {
public:
	// Constructor
	GameMapChangeOrientationMessage() {};
	// Copy constructor
	GameMapChangeOrientationMessage(const GameMapChangeOrientationMessage& other) = default;

	// Copy operator
	GameMapChangeOrientationMessage& operator=(const GameMapChangeOrientationMessage& other) = default;
	// Destructor
	~GameMapChangeOrientationMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 5147;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	ActorOrientation orientation;
};

#endif