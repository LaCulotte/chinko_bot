#ifndef PROTOCOLREQUIRED_MESSAGE_H
#define PROTOCOLREQUIRED_MESSAGE_H

#include "PrefixedMessage.h"


class ProtocolRequired : public PrefixedMessage {
public:
	// Constructor
	ProtocolRequired() {};
	// Copy constructor
	ProtocolRequired(const ProtocolRequired& other) = default;

	// Copy operator
	ProtocolRequired& operator=(const ProtocolRequired& other) = default;
	// Destructor
	~ProtocolRequired() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 4849;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	string version = "";
};

#endif