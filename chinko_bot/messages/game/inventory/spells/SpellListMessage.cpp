#include "SpellListMessage.h"

bool SpellListMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeBool(spellPrevisualization);
	output->writeShort(spells.size());
	for(int i = 0; i < spells.size(); i++) {
		spells[i].serialize(output);
	}

    return true;
}

bool SpellListMessage::deserialize(sp<MessageDataBuffer> input) {
	spellPrevisualization = input->readBool();
	int spells_size = input->readShort();
	for(int i = 0; i < spells_size; i++) {
		SpellItem spell;

		if(!spell.deserialize(input))
			return false;
		spells.push_back(spell);
	}

    return true;
}
