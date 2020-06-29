#include "ObjectEffect.h"

bool ObjectEffect::serialize(shared_ptr<MessageDataBuffer> output) {
	output->writeVarShort(actionId);

	return true;
}

bool ObjectEffect::deserialize(shared_ptr<MessageDataBuffer> input) {
	actionId = input->readVarShort();

	return true;
}
