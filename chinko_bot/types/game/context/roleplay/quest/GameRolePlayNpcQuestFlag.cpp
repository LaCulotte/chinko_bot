#include "GameRolePlayNpcQuestFlag.h"

bool GameRolePlayNpcQuestFlag::serialize(sp<MessageDataBuffer> output) {
	output->writeShort(questsToValidId.size());
	for(int i = 0; i < questsToValidId.size(); i++) {
		output->writeVarShort(questsToValidId[i]);
	}
	output->writeShort(questsToStartId.size());
	for(int i = 0; i < questsToStartId.size(); i++) {
		output->writeVarShort(questsToStartId[i]);
	}

    return true;
}

bool GameRolePlayNpcQuestFlag::deserialize(sp<MessageDataBuffer> input) {
	int questsToValidId_size = input->readShort();
	for(int i = 0; i < questsToValidId_size; i++) {
		int questsToValidI;

		questsToValidI = input->readVarShort();
		questsToValidId.push_back(questsToValidI);
	}
	int questsToStartId_size = input->readShort();
	for(int i = 0; i < questsToStartId_size; i++) {
		int questsToStartI;

		questsToStartI = input->readVarShort();
		questsToStartId.push_back(questsToStartI);
	}

    return true;
}
