#include "CurrentMapMessage.h"

bool CurrentMapMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeDouble(mapId);
	output->writeUTF(mapKey);

    return true;
}

bool CurrentMapMessage::deserialize(sp<MessageDataBuffer> input) {
	mapId = input->readDouble();
	mapKey = input->readUTF();

    return true;
}
