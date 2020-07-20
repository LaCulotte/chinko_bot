#include "InteractiveElementWithAgeBonus.h"

bool InteractiveElementWithAgeBonus::serialize(sp<MessageDataBuffer> output) {
	InteractiveElement::serialize(output);

	output->writeShort(ageBonus);

    return true;
}

bool InteractiveElementWithAgeBonus::deserialize(sp<MessageDataBuffer> input) {
	InteractiveElement::deserialize(input);

	ageBonus = input->readShort();

    return true;
}
