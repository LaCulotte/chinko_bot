#include "ObjectsQuantityMessage.h"

bool ObjectsQuantityMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeShort(objectsUIDAndQty.size());
	for(int i = 0; i < objectsUIDAndQty.size(); i++) {
		objectsUIDAndQty[i].serialize(output);
	}

    return true;
}

bool ObjectsQuantityMessage::deserialize(sp<MessageDataBuffer> input) {
	int objectsUIDAndQty_size = input->readShort();
	for(int i = 0; i < objectsUIDAndQty_size; i++) {
		ObjectItemQuantity objectsUIDAndQt;

		if(!objectsUIDAndQt.deserialize(input))
			return false;
		objectsUIDAndQty.push_back(objectsUIDAndQt);
	}

    return true;
}
