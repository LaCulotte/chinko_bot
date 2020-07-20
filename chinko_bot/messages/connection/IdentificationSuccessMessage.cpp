#include "IdentificationSuccessMessage.h"

bool IdentificationSuccessMessage::serialize(sp<MessageDataBuffer> output) {
	int flags = (hasConsoleRight<<1) | (wasAlreadyConnected<<2) | (hasRights<<0);
	output->writeByte(flags);

	output->writeUTF(login);
	output->writeUTF(nickname);
	output->writeInt(accountId);
	output->writeByte(communityId);
	output->writeUTF(secretQuestion);
	output->writeDouble(accountCreation);
	output->writeDouble(subscriptionElapsedDuration);
	output->writeDouble(subscriptionEndDate);
	output->writeByte(havenbagAvailableRoom);

    return true;
}

bool IdentificationSuccessMessage::deserialize(sp<MessageDataBuffer> input) {
	int flags = input->readByte();
	hasConsoleRight = flags & (1 << 1);
	wasAlreadyConnected = flags & (1 << 2);
	hasRights = flags & (1 << 0);

	login = input->readUTF();
	nickname = input->readUTF();
	accountId = input->readInt();
	communityId = input->readByte();
	secretQuestion = input->readUTF();
	accountCreation = input->readDouble();
	subscriptionElapsedDuration = input->readDouble();
	subscriptionEndDate = input->readDouble();
	havenbagAvailableRoom = input->readByte();

    return true;
}
