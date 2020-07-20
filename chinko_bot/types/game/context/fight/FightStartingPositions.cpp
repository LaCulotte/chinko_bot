#include "FightStartingPositions.h"

bool FightStartingPositions::serialize(sp<MessageDataBuffer> output) {
	output->writeShort(positionsForChallengers.size());
	for(int i = 0; i < positionsForChallengers.size(); i++) {
		output->writeVarShort(positionsForChallengers[i]);
	}
	output->writeShort(positionsForDefenders.size());
	for(int i = 0; i < positionsForDefenders.size(); i++) {
		output->writeVarShort(positionsForDefenders[i]);
	}

    return true;
}

bool FightStartingPositions::deserialize(sp<MessageDataBuffer> input) {
	int positionsForChallengers_size = input->readShort();
	for(int i = 0; i < positionsForChallengers_size; i++) {
		int positionsForChallenger;

		positionsForChallenger = input->readVarShort();
		positionsForChallengers.push_back(positionsForChallenger);
	}
	int positionsForDefenders_size = input->readShort();
	for(int i = 0; i < positionsForDefenders_size; i++) {
		int positionsForDefender;

		positionsForDefender = input->readVarShort();
		positionsForDefenders.push_back(positionsForDefender);
	}

    return true;
}
