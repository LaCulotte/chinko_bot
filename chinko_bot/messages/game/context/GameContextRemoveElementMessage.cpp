#include "GameContextRemoveElementMessage.h"

bool GameContextRemoveElementMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeDouble(id);

    return true;
}

bool GameContextRemoveElementMessage::deserialize(sp<MessageDataBuffer> input) {
	id = input->readDouble();

    return true;
}
