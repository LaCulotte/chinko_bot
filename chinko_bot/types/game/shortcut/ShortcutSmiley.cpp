#include "ShortcutSmiley.h"

bool ShortcutSmiley::serialize(sp<MessageDataBuffer> output) {
	Shortcut::serialize(output);

	output->writeVarShort(smileyId);

    return true;
}

bool ShortcutSmiley::deserialize(sp<MessageDataBuffer> input) {
	Shortcut::deserialize(input);

	smileyId = input->readVarShort();

    return true;
}
