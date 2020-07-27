#include "ClientKeyMessage.h"

bool ClientKeyMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeUTF(key);

    if(withHash) {
        for(int i = 0; i < 48; i++)
            output->writeByte(rand() % 256);
    }

    return true;
}

bool ClientKeyMessage::deserialize(sp<MessageDataBuffer> input) {
	key = input->readUTF();

    return true;
}
