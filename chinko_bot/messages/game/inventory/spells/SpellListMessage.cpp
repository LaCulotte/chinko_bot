#include "SpellListMessage.h"

bool SpellListMessage::serialize(shared_ptr<MessageDataBuffer> output) {

	output->writeBool(previsualisation);

	output->writeShort(spells.size());
	for(SpellItem spell : spells){
		if(!spell.serialize(output))
			return false;
	}

	return true;
}

bool SpellListMessage::deserialize(shared_ptr<MessageDataBuffer> input) {

	previsualisation = input->readBool();

	int spellsLength = input->readShort();
	for(int i = 0; i < spellsLength; i++) {
		SpellItem spell;
		if(spell.deserialize(input)){
			spells.push_back(spell);
		} else {
			return false;
		}
	}

	return true;
}
