#ifndef INTERACTIVEUSEENDEDMESSAGE_MESSAGE_H
#define INTERACTIVEUSEENDEDMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class InteractiveUseEndedMessage : public PrefixedMessage {
public:
	// Constructor
	InteractiveUseEndedMessage() {};
	// Copy constructor
	InteractiveUseEndedMessage(const InteractiveUseEndedMessage& other) = default;

	// Copy operator
	InteractiveUseEndedMessage& operator=(const InteractiveUseEndedMessage& other) = default;
	// Destructor
	~InteractiveUseEndedMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 785;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int skillId = 0;
	int elemId = 0;
};

#endif