#include "KamasUpdateMessage.h"

bool KamasUpdateMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeVarInt64(kamasTotal);

    return true;
}

bool KamasUpdateMessage::deserialize(sp<MessageDataBuffer> input) {
	kamasTotal = input->readVarInt64();

    return true;
}
