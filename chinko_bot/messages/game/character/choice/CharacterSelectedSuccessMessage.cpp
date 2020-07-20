#include "CharacterSelectedSuccessMessage.h"

bool CharacterSelectedSuccessMessage::serialize(sp<MessageDataBuffer> output) {
	infos.serialize(output);
	output->writeBool(isCollectingStats);

    return true;
}

bool CharacterSelectedSuccessMessage::deserialize(sp<MessageDataBuffer> input) {
	if(!infos.deserialize(input))
		return false;
	isCollectingStats = input->readBool();

    return true;
}
