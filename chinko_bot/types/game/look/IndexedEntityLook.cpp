#include "IndexedEntityLook.h"

bool IndexedEntityLook::serialize(sp<MessageDataBuffer> output) {
	look.serialize(output);
	output->writeByte(index);

    return true;
}

bool IndexedEntityLook::deserialize(sp<MessageDataBuffer> input) {
	if(!look.deserialize(input))
		return false;
	index = input->readByte();

    return true;
}
