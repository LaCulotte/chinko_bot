#include "FightLoot.h"

bool FightLoot::serialize(sp<MessageDataBuffer> output) {
	output->writeShort(objects.size());
	for(int i = 0; i < objects.size(); i++) {
		output->writeVarInt(objects[i]);
	}
	output->writeVarInt64(kamas);

    return true;
}

bool FightLoot::deserialize(sp<MessageDataBuffer> input) {
	int objects_size = input->readShort();
	for(int i = 0; i < objects_size; i++) {
		int object;

		object = input->readVarInt();
		objects.push_back(object);
	}
	kamas = input->readVarInt64();

    return true;
}
