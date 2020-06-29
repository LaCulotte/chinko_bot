#ifndef SEQUENCENUMBER_MESSAGE_H
#define SEQUENCENUMBER_MESSAGE_H

#include "PrefixedMessage.h"

class SequenceNumberMessage : public PrefixedMessage {
public: 
	// Constructor
	SequenceNumberMessage() {};
	// Constructor with sequenceNumber initialization
	SequenceNumberMessage(int sequenceNumber) { this->sequenceNumber = sequenceNumber; };
	// Copy constructor
	SequenceNumberMessage(const SequenceNumberMessage& other) = default;

	// Copy operator
	SequenceNumberMessage& operator=(const SequenceNumberMessage& other) = default;
	// Destructor
	~SequenceNumberMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 6317;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int sequenceNumber;

};

#endif