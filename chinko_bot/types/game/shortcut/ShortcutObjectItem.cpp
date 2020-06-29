#include "ShortcutObjectItem.h"

bool ShortcutObjectItem::serialize(shared_ptr<MessageDataBuffer> output) {
	if(!ShortcutObject::serialize(output))
		return false;

	output->writeInt(itemUID);
	output->writeInt(itemGID);

	return true;
}

bool ShortcutObjectItem::deserialize(shared_ptr<MessageDataBuffer> input) {
	if(!ShortcutObject::deserialize(input))
		return false;

	itemUID = input->readInt();
	itemGID = input->readInt();

	return true;
}
