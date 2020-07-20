#include "ObjectEffect.h"

bool ObjectEffect::serialize(sp<MessageDataBuffer> output) {
	output->writeVarShort(actionId);

    return true;
}

bool ObjectEffect::deserialize(sp<MessageDataBuffer> input) {
	actionId = input->readVarShort();

    return true;
}
