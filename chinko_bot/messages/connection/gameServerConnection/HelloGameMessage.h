#ifndef HELLOGAME_MESSAGE_H
#define HELLOGAME_MESSAGE_H

#include "PrefixedMessage.h"

class HelloGameMessage : public PrefixedMessage {
public: 
	// Constructor
	HelloGameMessage() {};
	// Copy constructor
	HelloGameMessage(const HelloGameMessage& other) = default;

	// Copy operator
	HelloGameMessage& operator=(const HelloGameMessage& other) = default;
	// Destructor
	~HelloGameMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 101;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override { return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override { return true; };

};

#endif