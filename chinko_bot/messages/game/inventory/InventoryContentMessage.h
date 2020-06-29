#ifndef INVENTORYCONTENT_MESSAGE_H
#define INVENTORYCONTENT_MESSAGE_H

#include "PrefixedMessage.h"
#include "ObjectItem.h"

class InventoryContentMessage : public PrefixedMessage {
public: 
	// Constructor
	InventoryContentMessage() {};
	// Copy constructor
	InventoryContentMessage(const InventoryContentMessage& other) = default;

	// Copy operator
	InventoryContentMessage& operator=(const InventoryContentMessage& other) = default;
	// Destructor
	~InventoryContentMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 3016;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<ObjectItem> objects;
	uint64_t kamas;

};

#endif