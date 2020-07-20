#include "GameContextActorPositionInformations.h"

bool GameContextActorPositionInformations::serialize(sp<MessageDataBuffer> output) {
	output->writeDouble(contextualId);
	output->writeShort(disposition->getId());
	disposition->serialize(output);

    return true;
}

bool GameContextActorPositionInformations::deserialize(sp<MessageDataBuffer> input) {
	contextualId = input->readDouble();
	int disposition_TypeId = input->readShort();
	disposition = dynamic_pointer_cast<EntityDispositionInformations>(NetworkTypeHandler::getInstance()->getTypeById(disposition_TypeId));

	if(!disposition || !disposition->deserialize(input))
		return false;


    return true;
}
