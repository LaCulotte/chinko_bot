#include "ChangeMapMessage.h"

bool ChangeMapMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeDouble(mapId);
	output->writeBool(autopilot);

    return true;
}

bool ChangeMapMessage::deserialize(sp<MessageDataBuffer> input) {
	mapId = input->readDouble();
	autopilot = input->readBool();

    return true;
}
