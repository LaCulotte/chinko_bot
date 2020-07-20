#include "GameRolePlayMountInformations.h"

bool GameRolePlayMountInformations::serialize(sp<MessageDataBuffer> output) {
	GameRolePlayNamedActorInformations::serialize(output);

	output->writeUTF(ownerName);
	output->writeByte(level);

    return true;
}

bool GameRolePlayMountInformations::deserialize(sp<MessageDataBuffer> input) {
	GameRolePlayNamedActorInformations::deserialize(input);

	ownerName = input->readUTF();
	level = input->readByte();

    return true;
}
