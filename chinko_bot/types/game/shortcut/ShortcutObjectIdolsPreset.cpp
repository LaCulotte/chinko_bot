#include "ShortcutObjectIdolsPreset.h"

bool ShortcutObjectIdolsPreset::serialize(shared_ptr<MessageDataBuffer> output) {
	if(!ShortcutObject::serialize(output))
		return false;

	output->writeShort(presetId);

	return true;
}

bool ShortcutObjectIdolsPreset::deserialize(shared_ptr<MessageDataBuffer> input) {
	if(!ShortcutObject::deserialize(input))
		return false;

	presetId = input->readShort();

	return true;
}
