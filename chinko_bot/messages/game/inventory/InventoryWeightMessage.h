#ifndef INVENTORYWEIGHT_MESSAGE_H
#define INVENTORYWEIGHT_MESSAGE_H

#include "PrefixedMessage.h"

class InventoryWeightMessage : public PrefixedMessage {
public: 
	// Constructor
	InventoryWeightMessage() {};
	// Copy constructor
	InventoryWeightMessage(const InventoryWeightMessage& other) = default;

	// Copy operator
	InventoryWeightMessage& operator=(const InventoryWeightMessage& other) = default;
	// Destructor
	~InventoryWeightMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 3009;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int inventoryWeight;
	int shopWeight;
	int maxWeight;

};

#endif