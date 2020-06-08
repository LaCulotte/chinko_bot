#ifndef PROTOCOLREQUIRED_MESSAGE_H
#define PROTOCOLREQUIRED_MESSAGE_H

#include "PrefixedMessage.h"

class ProtocolRequiredMessage : public PrefixedMessage {
public: 
	// Constructor
	ProtocolRequiredMessage() {};
	// Constructor with version initialization
	ProtocolRequiredMessage(int requiredVersion, int currentVersion);
	// Copy constructor
	ProtocolRequiredMessage(const ProtocolRequiredMessage& other) = default;

	// Copy operator
	ProtocolRequiredMessage& operator=(const ProtocolRequiredMessage& other) = default;
	// Destructor
	~ProtocolRequiredMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 1;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int currentVersion;
	int requiredVersion;

};

#endif