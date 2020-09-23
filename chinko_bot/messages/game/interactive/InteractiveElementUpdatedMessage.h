#ifndef INTERACTIVEELEMENTUPDATEDMESSAGE_MESSAGE_H
#define INTERACTIVEELEMENTUPDATEDMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "InteractiveElement.h"

class InteractiveElementUpdatedMessage : public PrefixedMessage {
public:
	// Constructor
	InteractiveElementUpdatedMessage() {};
	// Copy constructor
	InteractiveElementUpdatedMessage(const InteractiveElementUpdatedMessage& other) = default;

	// Copy operator
	InteractiveElementUpdatedMessage& operator=(const InteractiveElementUpdatedMessage& other) = default;
	// Destructor
	~InteractiveElementUpdatedMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 9817;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	InteractiveElement interactiveElement;
};

#endif