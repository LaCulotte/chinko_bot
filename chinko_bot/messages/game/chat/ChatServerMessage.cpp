#include "ChatServerMessage.h"

bool ChatServerMessage::serialize(sp<MessageDataBuffer> output) {
	ChatAbstractServerMessage::serialize(output);

	output->writeDouble(senderId);
	output->writeUTF(senderName);
	output->writeUTF(prefix);
	output->writeInt(senderAccountId);

    return true;
}

bool ChatServerMessage::deserialize(sp<MessageDataBuffer> input) {
	ChatAbstractServerMessage::deserialize(input);

	senderId = input->readDouble();
	senderName = input->readUTF();
	prefix = input->readUTF();
	senderAccountId = input->readInt();

    return true;
}
