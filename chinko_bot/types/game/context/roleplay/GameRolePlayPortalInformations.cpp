#include "GameRolePlayPortalInformations.h"

bool GameRolePlayPortalInformations::serialize(sp<MessageDataBuffer> output) {
	GameRolePlayActorInformations::serialize(output);

	output->writeShort(portal->getId());
	portal->serialize(output);

    return true;
}

bool GameRolePlayPortalInformations::deserialize(sp<MessageDataBuffer> input) {
	GameRolePlayActorInformations::deserialize(input);

	int portal_TypeId = input->readShort();
	portal = dynamic_pointer_cast<PortalInformation>(NetworkTypeHandler::getInstance()->getTypeById(portal_TypeId));

	if(!portal || !portal->deserialize(input))
		return false;


    return true;
}
