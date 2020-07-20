#include "ShortcutBarContentMessage.h"

bool ShortcutBarContentMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeByte(barType);
	output->writeShort(shortcuts.size());
	for(int i = 0; i < shortcuts.size(); i++) {
		output->writeShort(shortcuts[i]->getId());
		shortcuts[i]->serialize(output);
	}

    return true;
}

bool ShortcutBarContentMessage::deserialize(sp<MessageDataBuffer> input) {
	barType = input->readByte();
	int shortcuts_size = input->readShort();
	for(int i = 0; i < shortcuts_size; i++) {
		sp<Shortcut> shortcut(new Shortcut());

		int shortcut_TypeId = input->readShort();
		shortcut = dynamic_pointer_cast<Shortcut>(NetworkTypeHandler::getInstance()->getTypeById(shortcut_TypeId));
	
		if(!shortcut || !shortcut->deserialize(input))
			return false;
	
		shortcuts.push_back(shortcut);
	}

    return true;
}
