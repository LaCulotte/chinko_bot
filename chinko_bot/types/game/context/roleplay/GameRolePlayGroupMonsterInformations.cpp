#include "GameRolePlayGroupMonsterInformations.h"

bool GameRolePlayGroupMonsterInformations::serialize(sp<MessageDataBuffer> output) {
	GameRolePlayActorInformations::serialize(output);

	int flags0 = (hasAVARewardToken<<2) | (hasHardcoreDrop<<1) | (keyRingBonus<<0);
	output->writeByte(flags0);

	output->writeShort(staticInfos->getId());
	staticInfos->serialize(output);
	output->writeByte(lootShare);
	output->writeByte(alignmentSide);

    return true;
}

bool GameRolePlayGroupMonsterInformations::deserialize(sp<MessageDataBuffer> input) {
	GameRolePlayActorInformations::deserialize(input);

	int flags0 = input->readByte();
	hasAVARewardToken = flags0 & (1 << 2);
	hasHardcoreDrop = flags0 & (1 << 1);
	keyRingBonus = flags0 & (1 << 0);

	int staticInfos_TypeId = input->readShort();
	staticInfos = dynamic_pointer_cast<GroupMonsterStaticInformations>(NetworkTypeHandler::getInstance()->getTypeById(staticInfos_TypeId));

	if(!staticInfos || !staticInfos->deserialize(input))
		return false;

	lootShare = input->readByte();
	alignmentSide = input->readByte();

    return true;
}
