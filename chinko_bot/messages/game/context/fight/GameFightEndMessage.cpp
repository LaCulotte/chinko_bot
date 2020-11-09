#include "GameFightEndMessage.h"

bool GameFightEndMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeInt(duration);
	output->writeVarShort(rewardRate);
	output->writeShort(lootShareLimitMalus);
	output->writeShort(results.size());
	for(int i = 0; i < results.size(); i++) {
		output->writeShort(results[i]->getId());
		results[i]->serialize(output);
	}
	output->writeShort(namedPartyTeamsOutcomes.size());
	for(int i = 0; i < namedPartyTeamsOutcomes.size(); i++) {
		namedPartyTeamsOutcomes[i].serialize(output);
	}

    return true;
}

bool GameFightEndMessage::deserialize(sp<MessageDataBuffer> input) {
	duration = input->readInt();
	rewardRate = input->readVarShort();
	lootShareLimitMalus = input->readShort();
	int results_size = input->readShort();
	for(int i = 0; i < results_size; i++) {
		sp<FightResultListEntry> result(new FightResultListEntry());

		int result_TypeId = input->readShort();
		result = dynamic_pointer_cast<FightResultListEntry>(NetworkTypeHandler::getInstance()->getTypeById(result_TypeId));
	
		if(!result || !result->deserialize(input))
			return false;
	
		results.push_back(result);
	}
	int namedPartyTeamsOutcomes_size = input->readShort();
	for(int i = 0; i < namedPartyTeamsOutcomes_size; i++) {
		NamedPartyTeamWithOutcome namedPartyTeamsOutcome;

		if(!namedPartyTeamsOutcome.deserialize(input))
			return false;
		namedPartyTeamsOutcomes.push_back(namedPartyTeamsOutcome);
	}

    return true;
}
