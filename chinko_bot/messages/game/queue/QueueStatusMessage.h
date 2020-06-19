#ifndef QUEUESTATUS_MESSAGE_H
#define QUEUESTATUS_MESSAGE_H

#include "PrefixedMessage.h"

class QueueStatusMessage : public PrefixedMessage {
public: 
	// Constructor
	QueueStatusMessage() {};
	// Constructor
	QueueStatusMessage(int position, int total) { this->position = position; this->total = total; };
	// Copy constructor
	QueueStatusMessage(const QueueStatusMessage& other) = default;

	// Copy operator
	QueueStatusMessage& operator=(const QueueStatusMessage& other) = default;
	// Destructor
	~QueueStatusMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 6100;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int position;
	int total;

};

#endif