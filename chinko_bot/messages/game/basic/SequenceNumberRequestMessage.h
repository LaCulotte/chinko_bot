#ifndef SEQUENCENUMBERREQUESTMESSAGE_MESSAGE_H
#define SEQUENCENUMBERREQUESTMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class SequenceNumberRequestMessage : public PrefixedMessage {
public:
	// Constructor
	SequenceNumberRequestMessage() {};
	// Copy constructor
	SequenceNumberRequestMessage(const SequenceNumberRequestMessage& other) = default;

	// Copy operator
	SequenceNumberRequestMessage& operator=(const SequenceNumberRequestMessage& other) = default;
	// Destructor
	~SequenceNumberRequestMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 6316;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override{ return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override{ return true; };

};

#endif