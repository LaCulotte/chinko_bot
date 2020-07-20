#include "ShortcutEmote.h"

bool ShortcutEmote::serialize(sp<MessageDataBuffer> output) {
	Shortcut::serialize(output);

	output->writeByte(emoteId);

    return true;
}

bool ShortcutEmote::deserialize(sp<MessageDataBuffer> input) {
	Shortcut::deserialize(input);

	emoteId = input->readByte();

    return true;
}
