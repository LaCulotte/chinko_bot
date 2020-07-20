#include "IdentifiedEntityDispositionInformations.h"

bool IdentifiedEntityDispositionInformations::serialize(sp<MessageDataBuffer> output) {
	EntityDispositionInformations::serialize(output);

	output->writeDouble(id);

    return true;
}

bool IdentifiedEntityDispositionInformations::deserialize(sp<MessageDataBuffer> input) {
	EntityDispositionInformations::deserialize(input);

	id = input->readDouble();

    return true;
}
