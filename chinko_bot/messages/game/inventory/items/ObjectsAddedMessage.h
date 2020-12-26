#ifndef OBJECTSADDEDMESSAGE_MESSAGE_H
#define OBJECTSADDEDMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "ObjectItem.h"

class ObjectsAddedMessage : public PrefixedMessage {
public:
	// Constructor
	ObjectsAddedMessage() {};
	// Copy constructor
	ObjectsAddedMessage(const ObjectsAddedMessage& other) = default;

	// Copy operator
	ObjectsAddedMessage& operator=(const ObjectsAddedMessage& other) = default;
	// Destructor
	~ObjectsAddedMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 8179;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<ObjectItem> object;
};

#endif