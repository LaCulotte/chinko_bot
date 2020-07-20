#include "ClientKeyMessage.h"

bool ClientKeyMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeUTF(key);

    return true;
}

bool ClientKeyMessage::deserialize(sp<MessageDataBuffer> input) {
	key = input->readUTF();

    return true;
}
