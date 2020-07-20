#include "FightEntityDispositionInformations.h"

bool FightEntityDispositionInformations::serialize(sp<MessageDataBuffer> output) {
	EntityDispositionInformations::serialize(output);

	output->writeDouble(carryingCharacterId);

    return true;
}

bool FightEntityDispositionInformations::deserialize(sp<MessageDataBuffer> input) {
	EntityDispositionInformations::deserialize(input);

	carryingCharacterId = input->readDouble();

    return true;
}
