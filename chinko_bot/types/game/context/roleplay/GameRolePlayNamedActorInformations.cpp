#include "GameRolePlayNamedActorInformations.h"

bool GameRolePlayNamedActorInformations::serialize(sp<MessageDataBuffer> output) {
	GameRolePlayActorInformations::serialize(output);

	output->writeUTF(name);

    return true;
}

bool GameRolePlayNamedActorInformations::deserialize(sp<MessageDataBuffer> input) {
	GameRolePlayActorInformations::deserialize(input);

	name = input->readUTF();

    return true;
}
