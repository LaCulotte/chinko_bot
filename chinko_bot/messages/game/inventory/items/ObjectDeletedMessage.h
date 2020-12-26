#ifndef OBJECTDELETEDMESSAGE_MESSAGE_H
#define OBJECTDELETEDMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class ObjectDeletedMessage : public PrefixedMessage {
public:
	// Constructor
	ObjectDeletedMessage() {};
	// Copy constructor
	ObjectDeletedMessage(const ObjectDeletedMessage& other) = default;

	// Copy operator
	ObjectDeletedMessage& operator=(const ObjectDeletedMessage& other) = default;
	// Destructor
	~ObjectDeletedMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 112;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int objectUID = 0;
};

#endif