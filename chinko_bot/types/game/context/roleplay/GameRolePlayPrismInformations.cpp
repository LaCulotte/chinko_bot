#include "GameRolePlayPrismInformations.h"

bool GameRolePlayPrismInformations::serialize(sp<MessageDataBuffer> output) {
	GameRolePlayActorInformations::serialize(output);

	output->writeShort(prism->getId());
	prism->serialize(output);

    return true;
}

bool GameRolePlayPrismInformations::deserialize(sp<MessageDataBuffer> input) {
	GameRolePlayActorInformations::deserialize(input);

	int prism_TypeId = input->readShort();
	prism = dynamic_pointer_cast<PrismInformation>(NetworkTypeHandler::getInstance()->getTypeById(prism_TypeId));

	if(!prism || !prism->deserialize(input))
		return false;


    return true;
}
