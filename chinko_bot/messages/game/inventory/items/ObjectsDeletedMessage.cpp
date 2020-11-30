#include "ObjectsDeletedMessage.h"

bool ObjectsDeletedMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeShort(objectUID.size());
	for(int i = 0; i < objectUID.size(); i++) {
		output->writeVarInt(objectUID[i]);
	}

    return true;
}

bool ObjectsDeletedMessage::deserialize(sp<MessageDataBuffer> input) {
	int objectUID_size = input->readShort();
	for(int i = 0; i < objectUID_size; i++) {
		int objectUI;

		objectUI = input->readVarInt();
		objectUID.push_back(objectUI);
	}

    return true;
}
