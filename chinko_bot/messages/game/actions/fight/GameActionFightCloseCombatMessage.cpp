#include "GameActionFightCloseCombatMessage.h"

bool GameActionFightCloseCombatMessage::serialize(sp<MessageDataBuffer> output) {
	AbstractGameActionFightTargetedAbilityMessage::serialize(output);

	output->writeVarShort(weaponGenericId);

    return true;
}

bool GameActionFightCloseCombatMessage::deserialize(sp<MessageDataBuffer> input) {
	AbstractGameActionFightTargetedAbilityMessage::deserialize(input);

	weaponGenericId = input->readVarShort();

    return true;
}
