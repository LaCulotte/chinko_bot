#include "MapObstacle.h"

bool MapObstacle::serialize(sp<MessageDataBuffer> output) {
	output->writeVarShort(obstacleCellId);
	output->writeByte(state);

    return true;
}

bool MapObstacle::deserialize(sp<MessageDataBuffer> input) {
	obstacleCellId = input->readVarShort();
	state = input->readByte();

    return true;
}
