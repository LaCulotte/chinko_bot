#ifndef OBJECTSQUANTITYMESSAGE_MESSAGE_H
#define OBJECTSQUANTITYMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "ObjectItemQuantity.h"

class ObjectsQuantityMessage : public PrefixedMessage {
public:
	// Constructor
	ObjectsQuantityMessage() {};
	// Copy constructor
	ObjectsQuantityMessage(const ObjectsQuantityMessage& other) = default;

	// Copy operator
	ObjectsQuantityMessage& operator=(const ObjectsQuantityMessage& other) = default;
	// Destructor
	~ObjectsQuantityMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 739;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<ObjectItemQuantity> objectsUIDAndQty;
};

#endif