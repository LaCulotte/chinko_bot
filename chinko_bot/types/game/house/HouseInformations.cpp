#include "HouseInformations.h"

bool HouseInformations::serialize(sp<MessageDataBuffer> output) {
	output->writeVarInt(houseId);
	output->writeVarShort(modelId);

    return true;
}

bool HouseInformations::deserialize(sp<MessageDataBuffer> input) {
	houseId = input->readVarInt();
	modelId = input->readVarShort();

    return true;
}
