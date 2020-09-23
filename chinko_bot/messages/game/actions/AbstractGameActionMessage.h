#ifndef ABSTRACTGAMEACTIONMESSAGE_MESSAGE_H
#define ABSTRACTGAMEACTIONMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class AbstractGameActionMessage : public PrefixedMessage {
public:
	// Constructor
	AbstractGameActionMessage() {};
	// Copy constructor
	AbstractGameActionMessage(const AbstractGameActionMessage& other) = default;

	// Copy operator
	AbstractGameActionMessage& operator=(const AbstractGameActionMessage& other) = default;
	// Destructor
	~AbstractGameActionMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 8791;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	double sourceId = 0;
	int actionId = 0;
};

#endif