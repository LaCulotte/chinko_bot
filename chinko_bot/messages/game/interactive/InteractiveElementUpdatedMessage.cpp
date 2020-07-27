#include "InteractiveElementUpdatedMessage.h"

bool InteractiveElementUpdatedMessage::serialize(sp<MessageDataBuffer> output) {
	interactiveElement.serialize(output);

    return true;
}

bool InteractiveElementUpdatedMessage::deserialize(sp<MessageDataBuffer> input) {
	if(!interactiveElement.deserialize(input))
		return false;

    return true;
}
