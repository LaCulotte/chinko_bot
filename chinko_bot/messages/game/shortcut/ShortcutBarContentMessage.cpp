#include "ShortcutBarContentMessage.h"

bool ShortcutBarContentMessage::serialize(shared_ptr<MessageDataBuffer> output) {

	output->writeByte(barType);

	output->writeShort(shortcuts.size());
	for(sp<Shortcut> shortcut : shortcuts) {
		output->writeShort(shortcut->getId());
		shortcut->deserialize(output);
	}

	return true;
}

bool ShortcutBarContentMessage::deserialize(shared_ptr<MessageDataBuffer> input) {

	barType = input->readByte();

	int shortcutsSize = input->readShort();
	for(int i = 0; i < shortcutsSize; i++) {
		int shortcutId = input->readShort();
		sp<Shortcut> shortcut = dynamic_pointer_cast<Shortcut>(NetworkTypeHandler::getInstance()->getTypeById(shortcutId));

		if(!shortcut) {
			Logger::write("Error on ShortcutBarContentMessage deserialize : wrong shortcut id", LOG_ERROR);
			return false;
		}

		if(shortcut->deserialize(input)) {
			shortcuts.push_back(shortcut);
		} else {
			Logger::write("Error on ShortcutBarContentMessage deserialize : cannot deserialize shortcut", LOG_ERROR);
			return false;
		}
	}

	return true;
}
