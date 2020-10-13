#include "GameActionFightCastRequestMessage.h"

bool GameActionFightCastRequestMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeVarShort(spellId);
	output->writeShort(cellId);

	for(int i = 0; i < 48; i++)
		output->writeByte(rand() % 256);

    return true;
}

bool GameActionFightCastRequestMessage::deserialize(sp<MessageDataBuffer> input) {
	spellId = input->readVarShort();
	cellId = input->readShort();

    return true;
}
