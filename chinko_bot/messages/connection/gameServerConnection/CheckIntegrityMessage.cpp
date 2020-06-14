#include "CheckIntegrityMessage.h"

bool CheckIntegrityMessage::serialize(sp<MessageDataBuffer> output) {
    output->writeVarInt(256);
    for(int i = 0; i < 256; i++)
        output->writeByte(rand() % 256);

    return true;
}

bool CheckIntegrityMessage::deserialize(sp<MessageDataBuffer> input) {
    int dataSize = input->readVarInt();
    for(int i = 0; i < dataSize; i++) 
        input->readByte();

    return true;
}