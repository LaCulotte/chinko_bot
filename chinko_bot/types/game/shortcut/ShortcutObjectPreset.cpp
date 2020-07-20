#include "ShortcutObjectPreset.h"

bool ShortcutObjectPreset::serialize(sp<MessageDataBuffer> output) {
	ShortcutObject::serialize(output);

	output->writeShort(presetId);

    return true;
}

bool ShortcutObjectPreset::deserialize(sp<MessageDataBuffer> input) {
	ShortcutObject::deserialize(input);

	presetId = input->readShort();

    return true;
}
