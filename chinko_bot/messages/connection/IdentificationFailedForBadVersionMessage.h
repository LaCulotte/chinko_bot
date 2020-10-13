#ifndef IDENTIFICATIONFAILEDFORBADVERSIONMESSAGE_MESSAGE_H
#define IDENTIFICATIONFAILEDFORBADVERSIONMESSAGE_MESSAGE_H

#include "IdentificationFailedMessage.h"

#include "Version.h"

class IdentificationFailedForBadVersionMessage : public IdentificationFailedMessage {
public:
	// Constructor
	IdentificationFailedForBadVersionMessage() {};
	// Copy constructor
	IdentificationFailedForBadVersionMessage(const IdentificationFailedForBadVersionMessage& other) = default;

	// Copy operator
	IdentificationFailedForBadVersionMessage& operator=(const IdentificationFailedForBadVersionMessage& other) = default;
	// Destructor
	~IdentificationFailedForBadVersionMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 8091;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	Version requiredVersion;
};

#endif