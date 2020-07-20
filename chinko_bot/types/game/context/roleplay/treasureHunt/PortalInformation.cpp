#include "PortalInformation.h"

bool PortalInformation::serialize(sp<MessageDataBuffer> output) {
	output->writeInt(portalId);
	output->writeShort(areaId);

    return true;
}

bool PortalInformation::deserialize(sp<MessageDataBuffer> input) {
	portalId = input->readInt();
	areaId = input->readShort();

    return true;
}
