#include "PrismInformation.h"

bool PrismInformation::serialize(sp<MessageDataBuffer> output) {
	output->writeByte(type_id);
	output->writeByte(state);
	output->writeInt(nextVulnerabilityDate);
	output->writeInt(placementDate);
	output->writeVarInt(rewardTokenCount);

    return true;
}

bool PrismInformation::deserialize(sp<MessageDataBuffer> input) {
	type_id = input->readByte();
	state = input->readByte();
	nextVulnerabilityDate = input->readInt();
	placementDate = input->readInt();
	rewardTokenCount = input->readVarInt();

    return true;
}
