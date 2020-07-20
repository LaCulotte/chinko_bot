#include "GameRolePlayHumanoidInformations.h"

bool GameRolePlayHumanoidInformations::serialize(sp<MessageDataBuffer> output) {
	GameRolePlayNamedActorInformations::serialize(output);

	output->writeShort(humanoidInfo->getId());
	humanoidInfo->serialize(output);
	output->writeInt(accountId);

    return true;
}

bool GameRolePlayHumanoidInformations::deserialize(sp<MessageDataBuffer> input) {
	GameRolePlayNamedActorInformations::deserialize(input);

	int humanoidInfo_TypeId = input->readShort();
	humanoidInfo = dynamic_pointer_cast<HumanInformations>(NetworkTypeHandler::getInstance()->getTypeById(humanoidInfo_TypeId));

	if(!humanoidInfo || !humanoidInfo->deserialize(input))
		return false;

	accountId = input->readInt();

    return true;
}
