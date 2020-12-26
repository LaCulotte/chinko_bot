#ifndef OBJECTADDEDMESSAGE_MESSAGE_H
#define OBJECTADDEDMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "ObjectItem.h"

class ObjectAddedMessage : public PrefixedMessage {
public:
	// Constructor
	ObjectAddedMessage() {};
	// Copy constructor
	ObjectAddedMessage(const ObjectAddedMessage& other) = default;

	// Copy operator
	ObjectAddedMessage& operator=(const ObjectAddedMessage& other) = default;
	// Destructor
	~ObjectAddedMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 9393;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int origin = 0;
	ObjectItem object;
};

#endif