#include "InventoryContentMessage.h"

bool InventoryContentMessage::serialize(shared_ptr<MessageDataBuffer> output) {

	output->writeShort(objects.size());
	for(ObjectItem object : objects)
		object.serialize(output);

	output->writeVarInt64(kamas);

	return true;
}

bool InventoryContentMessage::deserialize(shared_ptr<MessageDataBuffer> input) {

	int objectsSize = input->readShort();
	for(int i = 0; i < objectsSize; i++) {
		ObjectItem object;
		if(object.deserialize(input)) {
			objects.push_back(object);
		} else {
			return false;
		}
	}

	kamas = input->readVarInt64();

	return true;
}
