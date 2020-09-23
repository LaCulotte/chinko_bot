#include "GameActionFightSpellCastMessage.h"

bool GameActionFightSpellCastMessage::serialize(sp<MessageDataBuffer> output) {
	AbstractGameActionFightTargetedAbilityMessage::serialize(output);

	output->writeVarShort(spellId);
	output->writeShort(spellLevel);
	output->writeShort(portalsIds.size());
	for(int i = 0; i < portalsIds.size(); i++) {
		output->writeShort(portalsIds[i]);
	}

    return true;
}

bool GameActionFightSpellCastMessage::deserialize(sp<MessageDataBuffer> input) {
	AbstractGameActionFightTargetedAbilityMessage::deserialize(input);

	spellId = input->readVarShort();
	spellLevel = input->readShort();
	int portalsIds_size = input->readShort();
	for(int i = 0; i < portalsIds_size; i++) {
		int portalsId;

		portalsId = input->readShort();
		portalsIds.push_back(portalsId);
	}

    return true;
}
