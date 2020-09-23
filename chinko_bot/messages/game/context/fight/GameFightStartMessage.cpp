#include "GameFightStartMessage.h"

bool GameFightStartMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeShort(idols.size());
	for(int i = 0; i < idols.size(); i++) {
		idols[i].serialize(output);
	}

    return true;
}

bool GameFightStartMessage::deserialize(sp<MessageDataBuffer> input) {
	int idols_size = input->readShort();
	for(int i = 0; i < idols_size; i++) {
		Idol idol;

		if(!idol.deserialize(input))
			return false;
		idols.push_back(idol);
	}

    return true;
}
