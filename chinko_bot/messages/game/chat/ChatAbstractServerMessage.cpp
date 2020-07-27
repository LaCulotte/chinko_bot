#include "ChatAbstractServerMessage.h"

bool ChatAbstractServerMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeByte(channel);
	output->writeUTF(content);
	output->writeInt(timestamp);
	output->writeUTF(fingerprint);

    return true;
}

bool ChatAbstractServerMessage::deserialize(sp<MessageDataBuffer> input) {
	channel = input->readByte();
	content = input->readUTF();
	timestamp = input->readInt();
	fingerprint = input->readUTF();

    return true;
}
