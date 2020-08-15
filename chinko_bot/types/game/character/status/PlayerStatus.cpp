#include "PlayerStatus.h"

bool PlayerStatus::serialize(sp<MessageDataBuffer> output) {
	output->writeByte(statusId);

    return true;
}

bool PlayerStatus::deserialize(sp<MessageDataBuffer> input) {
	statusId = input->readByte();

    return true;
}
