#include "ClientKeyMessage.h"

bool ClientKeyMessage::serialize(sp<MessageDataBuffer> output) {
    output->writeUTF(flashKey);
    return true;
}

bool ClientKeyMessage::deserialize(sp<MessageDataBuffer> input) {
    flashKey = input->readUTF();
    return true;
}