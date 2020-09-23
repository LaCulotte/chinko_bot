#ifndef INTERACTIVEUSEREQUESTMESSAGE_MESSAGE_H
#define INTERACTIVEUSEREQUESTMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class InteractiveUseRequestMessage : public PrefixedMessage {
public:
	// Constructor
	InteractiveUseRequestMessage() {};
	// Copy constructor
	InteractiveUseRequestMessage(const InteractiveUseRequestMessage& other) = default;

	// Copy operator
	InteractiveUseRequestMessage& operator=(const InteractiveUseRequestMessage& other) = default;
	// Destructor
	~InteractiveUseRequestMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 3068;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int skillInstanceUid = 0;
	int elemId = 0;
};

#endif