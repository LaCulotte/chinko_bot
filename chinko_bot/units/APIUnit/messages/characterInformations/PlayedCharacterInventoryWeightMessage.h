#ifndef INVENTORY_WEIGHT_MESSAGE_H
#define INVENTORY_WEIGHT_MESSAGE_H

#include "PrefixedMessage.h"

// Bot's character update : updates characters' weight
class PlayedCharacterInventoryWeightMessage : public PrefixedMessage {
public:
	// Constructor
	PlayedCharacterInventoryWeightMessage() {};
	// Copy constructor
	PlayedCharacterInventoryWeightMessage(const PlayedCharacterInventoryWeightMessage& other) = default;

	// Copy operator
	PlayedCharacterInventoryWeightMessage& operator=(const PlayedCharacterInventoryWeightMessage& other) = default;
	// Destructor
	~PlayedCharacterInventoryWeightMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 11036;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

    int weight;
    int maxWeight;
};

#endif