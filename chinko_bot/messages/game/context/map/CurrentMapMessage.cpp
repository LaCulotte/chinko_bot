#include "CurrentMapMessage.h"

bool CurrentMapMessage::serialize(shared_ptr<MessageDataBuffer> output) {

	output->writeDouble(mapId);
	output->writeUTF(mapKey);

	return true;
}

bool CurrentMapMessage::deserialize(shared_ptr<MessageDataBuffer> input) {

	mapId = input->readDouble();
	mapKey = input->readUTF();

	return true;
}
