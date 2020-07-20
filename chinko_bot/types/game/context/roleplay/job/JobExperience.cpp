#include "JobExperience.h"

bool JobExperience::serialize(sp<MessageDataBuffer> output) {
	output->writeByte(jobId);
	output->writeByte(jobLevel);
	output->writeVarInt64(jobXP);
	output->writeVarInt64(jobXpLevelFloor);
	output->writeVarInt64(jobXpNextLevelFloor);

    return true;
}

bool JobExperience::deserialize(sp<MessageDataBuffer> input) {
	jobId = input->readByte();
	jobLevel = input->readByte();
	jobXP = input->readVarInt64();
	jobXpLevelFloor = input->readVarInt64();
	jobXpNextLevelFloor = input->readVarInt64();

    return true;
}
