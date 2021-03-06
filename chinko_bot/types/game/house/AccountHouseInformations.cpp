#include "AccountHouseInformations.h"

bool AccountHouseInformations::serialize(sp<MessageDataBuffer> output) {
	HouseInformations::serialize(output);

	output->writeShort(houseInfos->getId());
	houseInfos->serialize(output);
	output->writeShort(worldX);
	output->writeShort(worldY);
	output->writeDouble(mapId);
	output->writeVarShort(subAreaId);

    return true;
}

bool AccountHouseInformations::deserialize(sp<MessageDataBuffer> input) {
	HouseInformations::deserialize(input);

	int houseInfos_TypeId = input->readShort();
	houseInfos = dynamic_pointer_cast<HouseInstanceInformations>(NetworkTypeHandler::getInstance()->getTypeById(houseInfos_TypeId));

	if(!houseInfos || !houseInfos->deserialize(input))
		return false;

	worldX = input->readShort();
	worldY = input->readShort();
	mapId = input->readDouble();
	subAreaId = input->readVarShort();

    return true;
}
