#include "CharacterLevelUpMessage.h"

bool CharacterLevelUpMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeVarShort(newLevel);

    return true;
}

bool CharacterLevelUpMessage::deserialize(sp<MessageDataBuffer> input) {
	newLevel = input->readVarShort();

    return true;
}
