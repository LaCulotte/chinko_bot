#include "GameMapMovementRequestMessage.h"

bool GameMapMovementRequestMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeShort(keyMovements.size());
	for(int i = 0; i < keyMovements.size(); i++) {
		output->writeShort(keyMovements[i]);
	}
	output->writeDouble(mapId);

	for(int i = 0; i < 48; i++)
		output->writeByte(rand() % 256);

    return true;
}

bool GameMapMovementRequestMessage::deserialize(sp<MessageDataBuffer> input) {
	int keyMovements_size = input->readShort();
	for(int i = 0; i < keyMovements_size; i++) {
		int keyMovement;

		keyMovement = input->readShort();
		keyMovements.push_back(keyMovement);
	}
	mapId = input->readDouble();

    return true;
}
