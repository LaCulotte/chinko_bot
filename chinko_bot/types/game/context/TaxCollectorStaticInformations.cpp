#include "TaxCollectorStaticInformations.h"

bool TaxCollectorStaticInformations::serialize(sp<MessageDataBuffer> output) {
	output->writeVarShort(firstNameId);
	output->writeVarShort(lastNameId);
	guildIdentity.serialize(output);

    return true;
}

bool TaxCollectorStaticInformations::deserialize(sp<MessageDataBuffer> input) {
	firstNameId = input->readVarShort();
	lastNameId = input->readVarShort();
	if(!guildIdentity.deserialize(input))
		return false;

    return true;
}
