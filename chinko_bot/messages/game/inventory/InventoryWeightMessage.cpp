#include "InventoryWeightMessage.h"

bool InventoryWeightMessage::serialize(shared_ptr<MessageDataBuffer> output) {

	output->writeVarInt(inventoryWeight);
	output->writeVarInt(shopWeight);
	output->writeVarInt(maxWeight);

	return true;
}

bool InventoryWeightMessage::deserialize(shared_ptr<MessageDataBuffer> input) {

	inventoryWeight = input->readVarInt();
	shopWeight = input->readVarInt();
	maxWeight = input->readVarInt();

	return true;
}
