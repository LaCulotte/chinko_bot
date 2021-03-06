#include "CharacterExperienceGainMessage.h"

bool CharacterExperienceGainMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeVarInt64(experienceCharacter);
	output->writeVarInt64(experienceMount);
	output->writeVarInt64(experienceGuild);
	output->writeVarInt64(experienceIncarnation);

    return true;
}

bool CharacterExperienceGainMessage::deserialize(sp<MessageDataBuffer> input) {
	experienceCharacter = input->readVarInt64();
	experienceMount = input->readVarInt64();
	experienceGuild = input->readVarInt64();
	experienceIncarnation = input->readVarInt64();

    return true;
}
