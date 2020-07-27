#ifndef INTERACTIVEUSEDMESSAGE_MESSAGE_H
#define INTERACTIVEUSEDMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class InteractiveUsedMessage : public PrefixedMessage {
public:
	// Constructor
	InteractiveUsedMessage() {};
	// Copy constructor
	InteractiveUsedMessage(const InteractiveUsedMessage& other) = default;

	// Copy operator
	InteractiveUsedMessage& operator=(const InteractiveUsedMessage& other) = default;
	// Destructor
	~InteractiveUsedMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 5745;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int duration = 0;
	int skillId = 0;
	bool canMove = false;
	int elemId = 0;
	uint64_t entityId = 0;
};

#endif