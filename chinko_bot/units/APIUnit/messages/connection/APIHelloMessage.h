#ifndef API_HELLO_MESSAGE_H
#define API_HELLO_MESSAGE_H

#include "PrefixedMessage.h"

// First message from the APIServer
class APIHelloMessage : public PrefixedMessage {
public:
	// Constructor
	APIHelloMessage() {};
	// Copy constructor
	APIHelloMessage(const APIHelloMessage& other) = default;

	// Copy operator
	APIHelloMessage& operator=(const APIHelloMessage& other) = default;
	// Destructor
	~APIHelloMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 11001;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override{ return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override{ return true; };

};


#endif