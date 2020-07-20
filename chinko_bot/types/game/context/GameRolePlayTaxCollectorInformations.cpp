#include "GameRolePlayTaxCollectorInformations.h"

bool GameRolePlayTaxCollectorInformations::serialize(sp<MessageDataBuffer> output) {
	GameRolePlayActorInformations::serialize(output);

	output->writeShort(identification->getId());
	identification->serialize(output);
	output->writeByte(guildLevel);
	output->writeInt(taxCollectorAttack);

    return true;
}

bool GameRolePlayTaxCollectorInformations::deserialize(sp<MessageDataBuffer> input) {
	GameRolePlayActorInformations::deserialize(input);

	int identification_TypeId = input->readShort();
	identification = dynamic_pointer_cast<TaxCollectorStaticInformations>(NetworkTypeHandler::getInstance()->getTypeById(identification_TypeId));

	if(!identification || !identification->deserialize(input))
		return false;

	guildLevel = input->readByte();
	taxCollectorAttack = input->readInt();

    return true;
}
