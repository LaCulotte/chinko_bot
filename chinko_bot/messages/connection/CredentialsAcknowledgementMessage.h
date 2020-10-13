#ifndef CREDENTIALSACKNOWLEDGEMENTMESSAGE_MESSAGE_H
#define CREDENTIALSACKNOWLEDGEMENTMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class CredentialsAcknowledgementMessage : public PrefixedMessage {
public:
	// Constructor
	CredentialsAcknowledgementMessage() {};
	// Copy constructor
	CredentialsAcknowledgementMessage(const CredentialsAcknowledgementMessage& other) = default;

	// Copy operator
	CredentialsAcknowledgementMessage& operator=(const CredentialsAcknowledgementMessage& other) = default;
	// Destructor
	~CredentialsAcknowledgementMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 9930;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override{ return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override{ return true; };

};

#endif