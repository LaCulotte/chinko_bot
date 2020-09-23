#include "GameActionMark.h"

bool GameActionMark::serialize(sp<MessageDataBuffer> output) {
	output->writeDouble(markAuthorId);
	output->writeByte(markTeamId);
	output->writeInt(markSpellId);
	output->writeShort(markSpellLevel);
	output->writeShort(markId);
	output->writeByte(markType);
	output->writeShort(markimpactCell);
	output->writeShort(cells.size());
	for(int i = 0; i < cells.size(); i++) {
		cells[i].serialize(output);
	}
	output->writeBool(active);

    return true;
}

bool GameActionMark::deserialize(sp<MessageDataBuffer> input) {
	markAuthorId = input->readDouble();
	markTeamId = input->readByte();
	markSpellId = input->readInt();
	markSpellLevel = input->readShort();
	markId = input->readShort();
	markType = input->readByte();
	markimpactCell = input->readShort();
	int cells_size = input->readShort();
	for(int i = 0; i < cells_size; i++) {
		GameActionMarkedCell cell;

		if(!cell.deserialize(input))
			return false;
		cells.push_back(cell);
	}
	active = input->readBool();

    return true;
}
