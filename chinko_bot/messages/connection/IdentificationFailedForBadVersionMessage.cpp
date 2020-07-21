#include "IdentificationFailedForBadVersionMessage.h"

bool IdentificationFailedForBadVersionMessage::serialize(sp<MessageDataBuffer> output) {
	IdentificationFailedMessage::serialize(output);

	requiredVersion.serialize(output);

    return true;
}

bool IdentificationFailedForBadVersionMessage::deserialize(sp<MessageDataBuffer> input) {
	IdentificationFailedMessage::deserialize(input);

	if(!requiredVersion.deserialize(input))
		return false;

    return true;
}
