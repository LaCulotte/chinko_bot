#include "ShortcutSpell.h"

bool ShortcutSpell::serialize(sp<MessageDataBuffer> output) {
	Shortcut::serialize(output);

	output->writeVarShort(spellId);

    return true;
}

bool ShortcutSpell::deserialize(sp<MessageDataBuffer> input) {
	Shortcut::deserialize(input);

	spellId = input->readVarShort();

    return true;
}
