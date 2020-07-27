#ifndef GAMEMAPMOVEMENTCONFIRMMESSAGE_MESSAGE_H
#define GAMEMAPMOVEMENTCONFIRMMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class GameMapMovementConfirmMessage : public PrefixedMessage {
public:
	// Constructor
	GameMapMovementConfirmMessage() {};
	// Copy constructor
	GameMapMovementConfirmMessage(const GameMapMovementConfirmMessage& other) = default;

	// Copy operator
	GameMapMovementConfirmMessage& operator=(const GameMapMovementConfirmMessage& other) = default;
	// Destructor
	~GameMapMovementConfirmMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 952;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override { return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override { return true; };

};

#endif