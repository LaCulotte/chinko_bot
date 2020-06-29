#include "ObjectItem.h"

bool ObjectItem::serialize(shared_ptr<MessageDataBuffer> output) {
	if(!Item::serialize(output))
		return false;

	output->writeShort(position);
	output->writeVarShort(objectGID);

	output->writeShort(effects.size());
	for(sp<ObjectEffect> effect : effects) {
		output->writeShort(effect->getId());
		effect->serialize(output);
	}

	output->writeVarInt(objectUID);
	output->writeVarInt(quantity);

	return true;
}

bool ObjectItem::deserialize(shared_ptr<MessageDataBuffer> input) {
	if(!Item::deserialize(input))
		return false;

	position = input->readShort();
	objectGID = input->readVarShort();

	int effectLength = input->readShort();
	for(int i = 0; i < effectLength; i++){
		int typeId = input->readShort();
		sp<ObjectEffect> effect = dynamic_pointer_cast<ObjectEffect>(NetworkTypeHandler::getInstance()->getTypeById(typeId));

		if(effect) {
			effect->deserialize(input);
			effects.push_back(effect);
		} else {
			return false;
		}
	}

	objectUID = input->readVarInt();
	quantity = input->readVarInt();
	
	return true;
}
