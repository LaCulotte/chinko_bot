#include "GameServerInformations.h"

bool GameServerInformations::serialize(sp<MessageDataBuffer> output) {
	int flags = (isMonoAccount<<0) | (isSelectable<<1);
	output->writeByte(flags);

	output->writeVarShort(id);
	output->writeByte(type);
	output->writeByte(status);
	output->writeByte(completion);
	output->writeByte(charactersCount);
	output->writeByte(charactersSlots);
	output->writeDouble(date);

    return true;
}

bool GameServerInformations::deserialize(sp<MessageDataBuffer> input) {
	int flags = input->readByte();
	isMonoAccount = flags & (1 << 0);
	isSelectable = flags & (1 << 1);

	id = input->readVarShort();
	type = input->readByte();
	status = input->readByte();
	completion = input->readByte();
	charactersCount = input->readByte();
	charactersSlots = input->readByte();
	date = input->readDouble();

    return true;
}
