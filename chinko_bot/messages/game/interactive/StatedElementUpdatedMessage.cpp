#include "StatedElementUpdatedMessage.h"

bool StatedElementUpdatedMessage::serialize(sp<MessageDataBuffer> output) {
	statedElement.serialize(output);

    return true;
}

bool StatedElementUpdatedMessage::deserialize(sp<MessageDataBuffer> input) {
	if(!statedElement.deserialize(input))
		return false;

    return true;
}
