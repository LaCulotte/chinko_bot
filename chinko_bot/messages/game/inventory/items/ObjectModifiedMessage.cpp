#include "ObjectModifiedMessage.h"

bool ObjectModifiedMessage::serialize(sp<MessageDataBuffer> output) {
	object.serialize(output);

    return true;
}

bool ObjectModifiedMessage::deserialize(sp<MessageDataBuffer> input) {
	if(!object.deserialize(input))
		return false;

    return true;
}
