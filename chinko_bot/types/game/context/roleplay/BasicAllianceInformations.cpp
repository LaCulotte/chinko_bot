#include "BasicAllianceInformations.h"

bool BasicAllianceInformations::serialize(sp<MessageDataBuffer> output) {
	AbstractSocialGroupInfos::serialize(output);

	output->writeVarInt(allianceId);
	output->writeUTF(allianceTag);

    return true;
}

bool BasicAllianceInformations::deserialize(sp<MessageDataBuffer> input) {
	AbstractSocialGroupInfos::deserialize(input);

	allianceId = input->readVarInt();
	allianceTag = input->readUTF();

    return true;
}
