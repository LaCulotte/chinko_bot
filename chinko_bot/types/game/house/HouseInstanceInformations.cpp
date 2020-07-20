#include "HouseInstanceInformations.h"

bool HouseInstanceInformations::serialize(sp<MessageDataBuffer> output) {
	int flags0 = (isSaleLocked<<2) | (isLocked<<1) | (secondHand<<0);
	output->writeByte(flags0);

	output->writeInt(instanceId);
	output->writeUTF(ownerName);
	output->writeVarInt64(price);

    return true;
}

bool HouseInstanceInformations::deserialize(sp<MessageDataBuffer> input) {
	int flags0 = input->readByte();
	isSaleLocked = flags0 & (1 << 2);
	isLocked = flags0 & (1 << 1);
	secondHand = flags0 & (1 << 0);

	instanceId = input->readInt();
	ownerName = input->readUTF();
	price = input->readVarInt64();

    return true;
}
