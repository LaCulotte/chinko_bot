#include "ShortcutObjectIdolsPreset.h"

bool ShortcutObjectIdolsPreset::serialize(sp<MessageDataBuffer> output) {
	ShortcutObject::serialize(output);

	output->writeShort(presetId);

    return true;
}

bool ShortcutObjectIdolsPreset::deserialize(sp<MessageDataBuffer> input) {
	ShortcutObject::deserialize(input);

	presetId = input->readShort();

    return true;
}
