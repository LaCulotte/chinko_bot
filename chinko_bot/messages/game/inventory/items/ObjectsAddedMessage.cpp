#include "ObjectsAddedMessage.h"

bool ObjectsAddedMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeShort(object.size());
	for(int i = 0; i < object.size(); i++) {
		object[i].serialize(output);
	}

    return true;
}

bool ObjectsAddedMessage::deserialize(sp<MessageDataBuffer> input) {
	int object_size = input->readShort();
	for(int i = 0; i < object_size; i++) {
		ObjectItem objec;

		if(!objec.deserialize(input))
			return false;
		object.push_back(objec);
	}

    return true;
}
