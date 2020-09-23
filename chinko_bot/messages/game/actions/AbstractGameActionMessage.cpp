#include "AbstractGameActionMessage.h"

bool AbstractGameActionMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeVarShort(actionId);
	output->writeDouble(sourceId);

    return true;
}

bool AbstractGameActionMessage::deserialize(sp<MessageDataBuffer> input) {
	actionId = input->readVarShort();
	sourceId = input->readDouble();

    return true;
}
