#include "BasicGuildInformations.h"

bool BasicGuildInformations::serialize(sp<MessageDataBuffer> output) {
	AbstractSocialGroupInfos::serialize(output);

	output->writeVarInt(guildId);
	output->writeUTF(guildName);
	output->writeByte(guildLevel);

    return true;
}

bool BasicGuildInformations::deserialize(sp<MessageDataBuffer> input) {
	AbstractSocialGroupInfos::deserialize(input);

	guildId = input->readVarInt();
	guildName = input->readUTF();
	guildLevel = input->readByte();

    return true;
}
