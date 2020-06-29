#include "ShortcutSmiley.h"

bool ShortcutSmiley::serialize(shared_ptr<MessageDataBuffer> output) {
	if(!Shortcut::serialize(output))
		return false;

	output->writeVarShort(smileyId);

	return true;
}

bool ShortcutSmiley::deserialize(shared_ptr<MessageDataBuffer> input) {
	if(!Shortcut::deserialize(input))
		return false;

	smileyId = input->readVarShort();

	return true;
}
