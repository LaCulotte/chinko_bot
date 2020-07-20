#include "HouseInformationsForGuild.h"

bool HouseInformationsForGuild::serialize(sp<MessageDataBuffer> output) {
	HouseInformations::serialize(output);

	output->writeInt(instanceId);
	output->writeBool(secondHand);
	output->writeUTF(ownerName);
	output->writeShort(worldX);
	output->writeShort(worldY);
	output->writeDouble(mapId);
	output->writeVarShort(subAreaId);
	output->writeShort(skillListIds.size());
	for(int i = 0; i < skillListIds.size(); i++) {
		output->writeInt(skillListIds[i]);
	}
	output->writeVarInt(guildshareParams);

    return true;
}

bool HouseInformationsForGuild::deserialize(sp<MessageDataBuffer> input) {
	HouseInformations::deserialize(input);

	instanceId = input->readInt();
	secondHand = input->readBool();
	ownerName = input->readUTF();
	worldX = input->readShort();
	worldY = input->readShort();
	mapId = input->readDouble();
	subAreaId = input->readVarShort();
	int skillListIds_size = input->readShort();
	for(int i = 0; i < skillListIds_size; i++) {
		int skillListId;

		skillListId = input->readInt();
		skillListIds.push_back(skillListId);
	}
	guildshareParams = input->readVarInt();

    return true;
}
