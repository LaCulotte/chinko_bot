#ifndef API_NOBOT_MESSAGE_H
#define API_NOBOT_MESSAGE_H

#include "PrefixedMessage.h"


class APINoBotMessage : public PrefixedMessage {
public:
	// Constructor
	APINoBotMessage() {};
	// Copy constructor
	APINoBotMessage(const APINoBotMessage& other) = default;

	// Copy operator
	APINoBotMessage& operator=(const APINoBotMessage& other) = default;
	// Destructor
	~APINoBotMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 11005;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override{ return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override{ return true; };

};


#endif