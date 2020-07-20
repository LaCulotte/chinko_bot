#include "HumanOptionObjectUse.h"

bool HumanOptionObjectUse::serialize(sp<MessageDataBuffer> output) {
	HumanOption::serialize(output);

	output->writeByte(delayTypeId);
	output->writeDouble(delayEndTime);
	output->writeVarShort(objectGID);

    return true;
}

bool HumanOptionObjectUse::deserialize(sp<MessageDataBuffer> input) {
	HumanOption::deserialize(input);

	delayTypeId = input->readByte();
	delayEndTime = input->readDouble();
	objectGID = input->readVarShort();

    return true;
}
