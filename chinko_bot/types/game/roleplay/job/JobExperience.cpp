#include "JobExperience.h"

bool JobExperience::serialize(shared_ptr<MessageDataBuffer> output) {

	output->writeByte(jobId);
	output->writeByte(jobLevel);

	output->writeVarInt64(jobXp);
	output->writeVarInt64(jobXpLevelFloor);
	output->writeVarInt64(jobXpNextLevelFloor);

	return true;
}

bool JobExperience::deserialize(shared_ptr<MessageDataBuffer> input) {

	jobId = input->readByte();
	jobLevel = input->readByte();

	jobXp = input->readVarInt64();
	jobXpLevelFloor = input->readVarInt64();
	jobXpNextLevelFloor = input->readVarInt64();

	return true;
}
