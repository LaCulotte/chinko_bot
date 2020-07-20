#include "StatedElement.h"

bool StatedElement::serialize(sp<MessageDataBuffer> output) {
	output->writeInt(elementId);
	output->writeVarShort(elementCellId);
	output->writeVarInt(elementState);
	output->writeBool(onCurrentMap);

    return true;
}

bool StatedElement::deserialize(sp<MessageDataBuffer> input) {
	elementId = input->readInt();
	elementCellId = input->readVarShort();
	elementState = input->readVarInt();
	onCurrentMap = input->readBool();

    return true;
}
