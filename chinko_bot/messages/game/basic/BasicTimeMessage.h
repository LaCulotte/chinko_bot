#ifndef BASICTIMEMESSAGE_MESSAGE_H
#define BASICTIMEMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class BasicTimeMessage : public PrefixedMessage {
public:
	// Constructor
	BasicTimeMessage() {};
	// Copy constructor
	BasicTimeMessage(const BasicTimeMessage& other) = default;

	// Copy operator
	BasicTimeMessage& operator=(const BasicTimeMessage& other) = default;
	// Destructor
	~BasicTimeMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 175;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	double timestamp = 0;
	int timezoneOffset = 0;
};

#endif