#include "BeginAuthentificationMessage.h"

bool BeginAuthentificationMessage::serialize(sp<MessageDataBuffer> output) {
    output->writeUTF(username);
    output->writeUTF(password);
    output->writeBool(autoConnect);

    return true;
}

bool BeginAuthentificationMessage::deserialize(sp<MessageDataBuffer> input) {
    username = input->readUTF();
    password = input->readUTF();
    autoConnect = input->readBool();

    return true;
}