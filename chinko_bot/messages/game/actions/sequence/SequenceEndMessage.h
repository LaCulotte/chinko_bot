#ifndef SEQUENCEENDMESSAGE_MESSAGE_H
#define SEQUENCEENDMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class SequenceEndMessage : public PrefixedMessage {
public:
	// Constructor
	SequenceEndMessage() {};
	// Copy constructor
	SequenceEndMessage(const SequenceEndMessage& other) = default;

	// Copy operator
	SequenceEndMessage& operator=(const SequenceEndMessage& other) = default;
	// Destructor
	~SequenceEndMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 8673;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int sequenceType = 0;
	double authorId = 0;
	int actionId = 0;
};

#endif