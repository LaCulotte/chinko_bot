#ifndef ITEMSADD_MESSAGE_H
#define ITEMSADD_MESSAGE_H

#include "PrefixedMessage.h"
#include "ItemInformations.h"

class ItemsAddMessage : public PrefixedMessage {
public:
	// Constructor
	ItemsAddMessage() {};
	// Constructor with items initialization
	ItemsAddMessage(vector<ItemInformations> items) { this->items = items; };
	// Copy constructor
	ItemsAddMessage(const ItemsAddMessage& other) = default;

	// Copy operator
	ItemsAddMessage& operator=(const ItemsAddMessage& other) = default;
	// Destructor
	~ItemsAddMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 11032;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<ItemInformations> items;

};

#endif