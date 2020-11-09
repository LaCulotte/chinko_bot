#include "JobLevelUpMessage.h"

bool JobLevelUpMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeByte(newLevel);
	jobsDescription.serialize(output);

    return true;
}

bool JobLevelUpMessage::deserialize(sp<MessageDataBuffer> input) {
	newLevel = input->readByte();
	if(!jobsDescription.deserialize(input))
		return false;

    return true;
}
