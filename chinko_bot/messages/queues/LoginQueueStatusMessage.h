#ifndef LOGINQUEUESTATUSMESSAGE_MESSAGE_H
#define LOGINQUEUESTATUSMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class LoginQueueStatusMessage : public PrefixedMessage {
public:
	// Constructor
	LoginQueueStatusMessage() {};
	// Copy constructor
	LoginQueueStatusMessage(const LoginQueueStatusMessage& other) = default;

	// Copy operator
	LoginQueueStatusMessage& operator=(const LoginQueueStatusMessage& other) = default;
	// Destructor
	~LoginQueueStatusMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 507;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int total = 0;
	int position = 0;
};

#endif