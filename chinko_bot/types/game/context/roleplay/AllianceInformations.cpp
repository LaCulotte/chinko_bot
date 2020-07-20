#include "AllianceInformations.h"

bool AllianceInformations::serialize(sp<MessageDataBuffer> output) {
	BasicNamedAllianceInformations::serialize(output);

	allianceEmblem.serialize(output);

    return true;
}

bool AllianceInformations::deserialize(sp<MessageDataBuffer> input) {
	BasicNamedAllianceInformations::deserialize(input);

	if(!allianceEmblem.deserialize(input))
		return false;

    return true;
}
