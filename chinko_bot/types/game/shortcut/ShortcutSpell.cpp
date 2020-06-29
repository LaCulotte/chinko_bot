#include "ShortcutSpell.h"

bool ShortcutSpell::serialize(shared_ptr<MessageDataBuffer> output) {
	if(!Shortcut::serialize(output))
		return false;

	output->writeVarShort(spellId);

	return true;
}

bool ShortcutSpell::deserialize(shared_ptr<MessageDataBuffer> input) {
	if(!Shortcut::deserialize(input))
		return false;

	spellId = input->readVarShort();

	return true;
}
