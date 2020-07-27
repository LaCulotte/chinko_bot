#include "SetCharacterRestrictionsMessage.h"

bool SetCharacterRestrictionsMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeDouble(actorId);
	restrictions.serialize(output);

    return true;
}

bool SetCharacterRestrictionsMessage::deserialize(sp<MessageDataBuffer> input) {
	actorId = input->readDouble();
	if(!restrictions.deserialize(input))
		return false;

    return true;
}
