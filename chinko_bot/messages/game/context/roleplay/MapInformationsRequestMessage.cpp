#include "MapInformationsRequestMessage.h"

bool MapInformationsRequestMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeDouble(mapId);

    return true;
}

bool MapInformationsRequestMessage::deserialize(sp<MessageDataBuffer> input) {
	mapId = input->readDouble();

    return true;
}
