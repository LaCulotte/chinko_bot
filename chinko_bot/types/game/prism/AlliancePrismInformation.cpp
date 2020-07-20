#include "AlliancePrismInformation.h"

bool AlliancePrismInformation::serialize(sp<MessageDataBuffer> output) {
	PrismInformation::serialize(output);

	alliance.serialize(output);

    return true;
}

bool AlliancePrismInformation::deserialize(sp<MessageDataBuffer> input) {
	PrismInformation::deserialize(input);

	if(!alliance.deserialize(input))
		return false;

    return true;
}
