#include "GameActionMarkedCell.h"

bool GameActionMarkedCell::serialize(sp<MessageDataBuffer> output) {
	output->writeVarShort(cellId);
	output->writeByte(zoneSize);
	output->writeInt(cellColor);
	output->writeByte(cellsType);

    return true;
}

bool GameActionMarkedCell::deserialize(sp<MessageDataBuffer> input) {
	cellId = input->readVarShort();
	zoneSize = input->readByte();
	cellColor = input->readInt();
	cellsType = input->readByte();

    return true;
}
