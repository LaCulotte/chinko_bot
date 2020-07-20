#include "GuildEmblem.h"

bool GuildEmblem::serialize(sp<MessageDataBuffer> output) {
	output->writeVarShort(symbolShape);
	output->writeInt(symbolColor);
	output->writeByte(backgroundShape);
	output->writeInt(backgroundColor);

    return true;
}

bool GuildEmblem::deserialize(sp<MessageDataBuffer> input) {
	symbolShape = input->readVarShort();
	symbolColor = input->readInt();
	backgroundShape = input->readByte();
	backgroundColor = input->readInt();

    return true;
}
