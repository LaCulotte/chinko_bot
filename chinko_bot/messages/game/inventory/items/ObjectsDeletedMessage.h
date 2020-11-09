#ifndef OBJECTSDELETEDMESSAGE_MESSAGE_H
#define OBJECTSDELETEDMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class ObjectsDeletedMessage : public PrefixedMessage {
public:
	// Constructor
	ObjectsDeletedMessage() {};
	// Copy constructor
	ObjectsDeletedMessage(const ObjectsDeletedMessage& other) = default;

	// Copy operator
	ObjectsDeletedMessage& operator=(const ObjectsDeletedMessage& other) = default;
	// Destructor
	~ObjectsDeletedMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 5628;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<int> objectUID;
};

#endif