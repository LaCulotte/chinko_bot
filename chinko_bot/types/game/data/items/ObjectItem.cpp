#include "ObjectItem.h"

bool ObjectItem::serialize(sp<MessageDataBuffer> output) {
	Item::serialize(output);

	output->writeShort(position);
	output->writeVarShort(objectGID);
	output->writeShort(effects.size());
	for(int i = 0; i < effects.size(); i++) {
		output->writeShort(effects[i]->getId());
		effects[i]->serialize(output);
	}
	output->writeVarInt(objectUID);
	output->writeVarInt(quantity);

    return true;
}

bool ObjectItem::deserialize(sp<MessageDataBuffer> input) {
	Item::deserialize(input);

	position = input->readShort();
	objectGID = input->readVarShort();
	int effects_size = input->readShort();
	for(int i = 0; i < effects_size; i++) {
		sp<ObjectEffect> effect(new ObjectEffect());

		int effect_TypeId = input->readShort();
		effect = dynamic_pointer_cast<ObjectEffect>(NetworkTypeHandler::getInstance()->getTypeById(effect_TypeId));
	
		if(!effect || !effect->deserialize(input))
			return false;
	
		effects.push_back(effect);
	}
	objectUID = input->readVarInt();
	quantity = input->readVarInt();

    return true;
}
