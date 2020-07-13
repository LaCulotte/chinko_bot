#include "ClientKeyMessage.h"

bool ClientKeyMessage::serialize(sp<MessageDataBuffer> output) {
    output->writeUTF(flashKey);

    if(withHash) {
        for(int i = 0; i < 48; i++)
            output->writeByte(rand() % 256);
    }

    return true;
}

bool ClientKeyMessage::deserialize(sp<MessageDataBuffer> input) {
    flashKey = input->readUTF();
    return true;
}