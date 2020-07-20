#include "AlternativeMonstersInGroupLightInformations.h"

bool AlternativeMonstersInGroupLightInformations::serialize(sp<MessageDataBuffer> output) {
	output->writeInt(playerCount);
	output->writeShort(monsters.size());
	for(int i = 0; i < monsters.size(); i++) {
		monsters[i].serialize(output);
	}

    return true;
}

bool AlternativeMonstersInGroupLightInformations::deserialize(sp<MessageDataBuffer> input) {
	playerCount = input->readInt();
	int monsters_size = input->readShort();
	for(int i = 0; i < monsters_size; i++) {
		MonsterInGroupLightInformations monster;

		if(!monster.deserialize(input))
			return false;
		monsters.push_back(monster);
	}

    return true;
}
