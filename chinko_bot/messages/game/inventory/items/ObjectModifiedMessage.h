#ifndef OBJECTMODIFIEDMESSAGE_MESSAGE_H
#define OBJECTMODIFIEDMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "ObjectItem.h"

class ObjectModifiedMessage : public PrefixedMessage {
public:
	// Constructor
	ObjectModifiedMessage() {};
	// Copy constructor
	ObjectModifiedMessage(const ObjectModifiedMessage& other) = default;

	// Copy operator
	ObjectModifiedMessage& operator=(const ObjectModifiedMessage& other) = default;
	// Destructor
	~ObjectModifiedMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 367;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	ObjectItem object;
};

#endif