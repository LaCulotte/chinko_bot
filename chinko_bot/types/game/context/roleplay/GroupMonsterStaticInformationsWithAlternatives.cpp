#include "GroupMonsterStaticInformationsWithAlternatives.h"

bool GroupMonsterStaticInformationsWithAlternatives::serialize(sp<MessageDataBuffer> output) {
	GroupMonsterStaticInformations::serialize(output);

	output->writeShort(alternatives.size());
	for(int i = 0; i < alternatives.size(); i++) {
		alternatives[i].serialize(output);
	}

    return true;
}

bool GroupMonsterStaticInformationsWithAlternatives::deserialize(sp<MessageDataBuffer> input) {
	GroupMonsterStaticInformations::deserialize(input);

	int alternatives_size = input->readShort();
	for(int i = 0; i < alternatives_size; i++) {
		AlternativeMonstersInGroupLightInformations alternative;

		if(!alternative.deserialize(input))
			return false;
		alternatives.push_back(alternative);
	}

    return true;
}
