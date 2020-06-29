#include "SpellItem.h"

bool SpellItem::serialize(shared_ptr<MessageDataBuffer> output) {
	if(!Item::serialize(output)) 
		return false;

	output->writeInt(spellId);
	output->writeShort(spellLevel);

	return true;
}

bool SpellItem::deserialize(shared_ptr<MessageDataBuffer> input) {
	if(!Item::deserialize(input)) 
		return false;

	spellId = input->readInt();
	spellLevel = input->readShort();

	return true;
}
