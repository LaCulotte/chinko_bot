#include "MapInformationsRequestMessage.h"

bool MapInformationsRequestMessage::serialize(shared_ptr<MessageDataBuffer> output) {

	output->writeDouble(mapId);

	return true;
}

bool MapInformationsRequestMessage::deserialize(shared_ptr<MessageDataBuffer> input) {

	mapId = input->readDouble();

	return true;
}
