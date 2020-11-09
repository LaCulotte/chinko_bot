#include "CharacterInformations.h"

bool CharacterInformations::serialize(sp<MessageDataBuffer> output) {
    output->writeInt64(id);
    output->writeUTF(name);
    output->writeByte(breed);
    output->writeBool(sex);
    output->writeByte(level);
    output->writeBool(isSelectable);

    return true;
}

bool CharacterInformations::deserialize(sp<MessageDataBuffer> input) {
    id = input->readInt64();
    name = input->readUTF();
    breed = input->readByte();
    sex = input->readBool();
    level = input->readByte();
    isSelectable = input->readBool();

    return true;
}