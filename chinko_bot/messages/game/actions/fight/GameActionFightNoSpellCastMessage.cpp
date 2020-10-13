#include "GameActionFightNoSpellCastMessage.h"

bool GameActionFightNoSpellCastMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeVarInt(spellLevelId);

    return true;
}

bool GameActionFightNoSpellCastMessage::deserialize(sp<MessageDataBuffer> input) {
	spellLevelId = input->readVarInt();

    return true;
}
