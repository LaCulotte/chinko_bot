#include "SpellItem.h"

bool SpellItem::serialize(sp<MessageDataBuffer> output) {
	Item::serialize(output);

	output->writeInt(spellId);
	output->writeShort(spellLevel);

    return true;
}

bool SpellItem::deserialize(sp<MessageDataBuffer> input) {
	Item::deserialize(input);

	spellId = input->readInt();
	spellLevel = input->readShort();

    return true;
}
