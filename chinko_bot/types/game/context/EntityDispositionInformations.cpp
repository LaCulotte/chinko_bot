#include "EntityDispositionInformations.h"

bool EntityDispositionInformations::serialize(sp<MessageDataBuffer> output) {
	output->writeShort(cellId);
	output->writeByte(direction);

    return true;
}

bool EntityDispositionInformations::deserialize(sp<MessageDataBuffer> input) {
	cellId = input->readShort();
	direction = input->readByte();

    return true;
}
