#ifndef APISERVER_FULL_MESSAGE_H
#define APISERVER_FULL_MESSAGE_H

#include "PrefixedMessage.h"

// The API Server is full, no more API connection can be accepted
class APIServerFullMessage : public PrefixedMessage {
public:
	// Constructor
	APIServerFullMessage() {};
	// Copy constructor
	APIServerFullMessage(const APIServerFullMessage& other) = default;

	// Copy operator
	APIServerFullMessage& operator=(const APIServerFullMessage& other) = default;
	// Destructor
	~APIServerFullMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 11002;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override{ return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override{ return true; };
};


#endif