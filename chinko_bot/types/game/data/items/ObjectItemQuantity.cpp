#include "ObjectItemQuantity.h"

bool ObjectItemQuantity::serialize(sp<MessageDataBuffer> output) {
	Item::serialize(output);

	output->writeVarInt(objectUID);
	output->writeVarInt(quantity);

    return true;
}

bool ObjectItemQuantity::deserialize(sp<MessageDataBuffer> input) {
	Item::deserialize(input);

	objectUID = input->readVarInt();
	quantity = input->readVarInt();

    return true;
}
