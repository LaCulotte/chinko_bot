#include "ShortcutObjectItem.h"

bool ShortcutObjectItem::serialize(sp<MessageDataBuffer> output) {
	ShortcutObject::serialize(output);

	output->writeInt(itemUID);
	output->writeInt(itemGID);

    return true;
}

bool ShortcutObjectItem::deserialize(sp<MessageDataBuffer> input) {
	ShortcutObject::deserialize(input);

	itemUID = input->readInt();
	itemGID = input->readInt();

    return true;
}
