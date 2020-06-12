#include "IdentificationSuccessMessage.h"

bool IdentificationSuccessMessage::serialize(sp<MessageDataBuffer> output) {
    uchar flags = hasRights | (hasConsoleRights << 1) | (wasAlreadyConnected << 2);
    output->writeByte(flags);

    output->writeUTF(username);
    output->writeUTF(nickname);

    output->writeInt(accountId);
    output->writeByte(communityId);

    output->writeUTF(secretQuestion);

    output->writeInt64(accountCreation);
    output->writeInt64(subscriptionElapsedDuration);
    output->writeInt64(subscriptionEndDate);

    output->writeByte(havenBagAvailableRoom);

    return true;
}

bool IdentificationSuccessMessage::deserialize(sp<MessageDataBuffer> input) {
    uchar flags = input->readByte();
    hasRights = flags & 1;
    hasConsoleRights = flags & 2;
    wasAlreadyConnected = flags & 4;

    username = input->readUTF();
    nickname = input->readUTF();

    accountId = input->readInt();
    communityId = input->readByte();
    secretQuestion = input->readUTF();

    accountCreation = input->readInt64();
    subscriptionElapsedDuration = input->readInt64();
    subscriptionEndDate = input->readInt64();

    havenBagAvailableRoom = input->readByte();

    return true;
}