#ifndef STATEDELEMENTUPDATEDMESSAGE_MESSAGE_H
#define STATEDELEMENTUPDATEDMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "StatedElement.h"

class StatedElementUpdatedMessage : public PrefixedMessage {
public:
	// Constructor
	StatedElementUpdatedMessage() {};
	// Copy constructor
	StatedElementUpdatedMessage(const StatedElementUpdatedMessage& other) = default;

	// Copy operator
	StatedElementUpdatedMessage& operator=(const StatedElementUpdatedMessage& other) = default;
	// Destructor
	~StatedElementUpdatedMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 5709;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	StatedElement statedElement;
};

#endif