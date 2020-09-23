#include "GameFightTurnListMessage.h"

bool GameFightTurnListMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeShort(ids.size());
	for(int i = 0; i < ids.size(); i++) {
		output->writeDouble(ids[i]);
	}
	output->writeShort(deadsIds.size());
	for(int i = 0; i < deadsIds.size(); i++) {
		output->writeDouble(deadsIds[i]);
	}

    return true;
}

bool GameFightTurnListMessage::deserialize(sp<MessageDataBuffer> input) {
	int ids_size = input->readShort();
	for(int i = 0; i < ids_size; i++) {
		double id;

		id = input->readDouble();
		ids.push_back(id);
	}
	int deadsIds_size = input->readShort();
	for(int i = 0; i < deadsIds_size; i++) {
		double deadsId;

		deadsId = input->readDouble();
		deadsIds.push_back(deadsId);
	}

    return true;
}
