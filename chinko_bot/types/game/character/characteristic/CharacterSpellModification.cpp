#include "CharacterSpellModification.h"

bool CharacterSpellModification::serialize(sp<MessageDataBuffer> output) {
	output->writeByte(modificationType);
	output->writeVarShort(spellId);
	value.serialize(output);

    return true;
}

bool CharacterSpellModification::deserialize(sp<MessageDataBuffer> input) {
	modificationType = input->readByte();
	spellId = input->readVarShort();
	if(!value.deserialize(input))
		return false;

    return true;
}
