#include "Shortcut.h"

bool Shortcut::serialize(sp<MessageDataBuffer> output) {
	output->writeByte(slot);

    return true;
}

bool Shortcut::deserialize(sp<MessageDataBuffer> input) {
	slot = input->readByte();

    return true;
}
