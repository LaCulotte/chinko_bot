#include "GameMapChangeOrientationMessage.h"

bool GameMapChangeOrientationMessage::serialize(sp<MessageDataBuffer> output) {
	orientation.serialize(output);

    return true;
}

bool GameMapChangeOrientationMessage::deserialize(sp<MessageDataBuffer> input) {
	if(!orientation.deserialize(input))
		return false;

    return true;
}
