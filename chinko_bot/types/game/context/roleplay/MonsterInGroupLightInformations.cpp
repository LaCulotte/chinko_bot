#include "MonsterInGroupLightInformations.h"

bool MonsterInGroupLightInformations::serialize(sp<MessageDataBuffer> output) {
	output->writeInt(genericId);
	output->writeByte(grade);
	output->writeShort(level);

    return true;
}

bool MonsterInGroupLightInformations::deserialize(sp<MessageDataBuffer> input) {
	genericId = input->readInt();
	grade = input->readByte();
	level = input->readShort();

    return true;
}
