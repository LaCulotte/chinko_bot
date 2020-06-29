#include "Shortcut.h"

bool Shortcut::serialize(shared_ptr<MessageDataBuffer> output) {
	output->writeByte(slot);

	return true;
}

bool Shortcut::deserialize(shared_ptr<MessageDataBuffer> input) {
	slot = input->readByte();

	return true;
}
