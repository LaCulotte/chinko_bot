#include "InventoryWeightMessage.h"

bool InventoryWeightMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeVarInt(inventoryWeight);
	output->writeVarInt(shopWeight);
	output->writeVarInt(weightMax);

    return true;
}

bool InventoryWeightMessage::deserialize(sp<MessageDataBuffer> input) {
	inventoryWeight = input->readVarInt();
	shopWeight = input->readVarInt();
	weightMax = input->readVarInt();

    return true;
}
