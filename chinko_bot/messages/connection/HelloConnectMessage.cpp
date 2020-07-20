#include "HelloConnectMessage.h"

bool HelloConnectMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeUTF(salt);
	output->writeVarInt(key.size());
	for(int i = 0; i < key.size(); i++) {
		output->writeByte(key[i]);
	}

    return true;
}

bool HelloConnectMessage::deserialize(sp<MessageDataBuffer> input) {
	salt = input->readUTF();
	int key_size = input->readVarInt();
	for(int i = 0; i < key_size; i++) {
		int ke;

		ke = input->readByte();
		key.push_back(ke);
	}

    return true;
}
