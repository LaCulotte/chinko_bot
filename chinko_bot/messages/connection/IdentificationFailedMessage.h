#ifndef IDENTIFICATIONFAILEDMESSAGE_MESSAGE_H
#define IDENTIFICATIONFAILEDMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class IdentificationFailedMessage : public PrefixedMessage {
public:
	// Constructor
	IdentificationFailedMessage() {};
	// Copy constructor
	IdentificationFailedMessage(const IdentificationFailedMessage& other) = default;

	// Copy operator
	IdentificationFailedMessage& operator=(const IdentificationFailedMessage& other) = default;
	// Destructor
	~IdentificationFailedMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 9617;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int reason = 99;
};

#endif