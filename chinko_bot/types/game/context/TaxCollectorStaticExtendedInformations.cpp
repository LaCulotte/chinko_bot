#include "TaxCollectorStaticExtendedInformations.h"

bool TaxCollectorStaticExtendedInformations::serialize(sp<MessageDataBuffer> output) {
	TaxCollectorStaticInformations::serialize(output);

	allianceIdentity.serialize(output);

    return true;
}

bool TaxCollectorStaticExtendedInformations::deserialize(sp<MessageDataBuffer> input) {
	TaxCollectorStaticInformations::deserialize(input);

	if(!allianceIdentity.deserialize(input))
		return false;

    return true;
}
