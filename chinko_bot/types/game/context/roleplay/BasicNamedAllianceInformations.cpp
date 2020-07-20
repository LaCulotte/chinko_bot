#include "BasicNamedAllianceInformations.h"

bool BasicNamedAllianceInformations::serialize(sp<MessageDataBuffer> output) {
	BasicAllianceInformations::serialize(output);

	output->writeUTF(allianceName);

    return true;
}

bool BasicNamedAllianceInformations::deserialize(sp<MessageDataBuffer> input) {
	BasicAllianceInformations::deserialize(input);

	allianceName = input->readUTF();

    return true;
}
