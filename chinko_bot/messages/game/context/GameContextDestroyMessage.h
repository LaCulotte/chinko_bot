#ifndef GAMECONTEXTDESTROYMESSAGE_MESSAGE_H
#define GAMECONTEXTDESTROYMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class GameContextDestroyMessage : public PrefixedMessage {
public:
	// Constructor
	GameContextDestroyMessage() {};
	// Copy constructor
	GameContextDestroyMessage(const GameContextDestroyMessage& other) = default;

	// Copy operator
	GameContextDestroyMessage& operator=(const GameContextDestroyMessage& other) = default;
	// Destructor
	~GameContextDestroyMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 5443;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override { return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override { return true; };

};

#endif