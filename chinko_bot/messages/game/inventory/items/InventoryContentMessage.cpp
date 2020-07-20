#include "InventoryContentMessage.h"

bool InventoryContentMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeShort(objects.size());
	for(int i = 0; i < objects.size(); i++) {
		objects[i].serialize(output);
	}
	output->writeVarInt64(kamas);

    return true;
}

bool InventoryContentMessage::deserialize(sp<MessageDataBuffer> input) {
	int objects_size = input->readShort();
	for(int i = 0; i < objects_size; i++) {
		ObjectItem object;

		if(!object.deserialize(input))
			return false;
		objects.push_back(object);
	}
	kamas = input->readVarInt64();

    return true;
}
