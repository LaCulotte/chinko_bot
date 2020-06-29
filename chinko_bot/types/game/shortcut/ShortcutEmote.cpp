#include "ShortcutEmote.h"

bool ShortcutEmote::serialize(shared_ptr<MessageDataBuffer> output) {
	if(!Shortcut::serialize(output))
		return false;

	output->writeByte(emoteId);

	return true;
}

bool ShortcutEmote::deserialize(shared_ptr<MessageDataBuffer> input) {
	if(!Shortcut::deserialize(input))
		return false;

	emoteId = input->readByte();

	return true;
}
