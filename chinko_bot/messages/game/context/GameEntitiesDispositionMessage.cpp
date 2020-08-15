#include "GameEntitiesDispositionMessage.h"

bool GameEntitiesDispositionMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeShort(dispositions.size());
	for(int i = 0; i < dispositions.size(); i++) {
		dispositions[i].serialize(output);
	}

    return true;
}

bool GameEntitiesDispositionMessage::deserialize(sp<MessageDataBuffer> input) {
	int dispositions_size = input->readShort();
	for(int i = 0; i < dispositions_size; i++) {
		IdentifiedEntityDispositionInformations disposition;

		if(!disposition.deserialize(input))
			return false;
		dispositions.push_back(disposition);
	}

    return true;
}
