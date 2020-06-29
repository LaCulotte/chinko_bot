#include "ShortcutObjectPreset.h"

bool ShortcutObjectPreset::serialize(shared_ptr<MessageDataBuffer> output) {
	if(!ShortcutObject::serialize(output))
		return false;

	output->writeShort(presetId);

	return true;
}

bool ShortcutObjectPreset::deserialize(shared_ptr<MessageDataBuffer> input) {
	if(!ShortcutObject::deserialize(input))
		return false;

	presetId = input->readShort();

	return true;
}
