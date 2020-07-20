#include "HumanOptionFollowers.h"

bool HumanOptionFollowers::serialize(sp<MessageDataBuffer> output) {
	HumanOption::serialize(output);

	output->writeShort(followingCharactersLook.size());
	for(int i = 0; i < followingCharactersLook.size(); i++) {
		followingCharactersLook[i].serialize(output);
	}

    return true;
}

bool HumanOptionFollowers::deserialize(sp<MessageDataBuffer> input) {
	HumanOption::deserialize(input);

	int followingCharactersLook_size = input->readShort();
	for(int i = 0; i < followingCharactersLook_size; i++) {
		IndexedEntityLook followingCharactersLoo;

		if(!followingCharactersLoo.deserialize(input))
			return false;
		followingCharactersLook.push_back(followingCharactersLoo);
	}

    return true;
}
