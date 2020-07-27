#include "GameMapMovementMessage.h"

bool GameMapMovementMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeShort(keyMovements.size());
	for(int i = 0; i < keyMovements.size(); i++) {
		output->writeShort(keyMovements[i]);
	}
	output->writeShort(forcedDirection);
	output->writeDouble(actorId);

    return true;
}

bool GameMapMovementMessage::deserialize(sp<MessageDataBuffer> input) {
	int keyMovements_size = input->readShort();
	for(int i = 0; i < keyMovements_size; i++) {
		int keyMovement;

		// TODO : read unsigned short, double, float, int et byte -> erreurs de signe
		keyMovement = (uint16_t) input->readShort();
		
		keyMovements.push_back(keyMovement);
	}
	forcedDirection = input->readShort();
	actorId = input->readDouble();

    return true;
}
