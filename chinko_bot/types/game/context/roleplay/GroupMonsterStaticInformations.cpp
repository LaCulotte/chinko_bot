#include "GroupMonsterStaticInformations.h"

bool GroupMonsterStaticInformations::serialize(sp<MessageDataBuffer> output) {
	mainCreatureLightInfos.serialize(output);
	output->writeShort(underlings.size());
	for(int i = 0; i < underlings.size(); i++) {
		underlings[i].serialize(output);
	}

    return true;
}

bool GroupMonsterStaticInformations::deserialize(sp<MessageDataBuffer> input) {
	if(!mainCreatureLightInfos.deserialize(input))
		return false;
	int underlings_size = input->readShort();
	for(int i = 0; i < underlings_size; i++) {
		MonsterInGroupInformations underling;

		if(!underling.deserialize(input))
			return false;
		underlings.push_back(underling);
	}

    return true;
}
