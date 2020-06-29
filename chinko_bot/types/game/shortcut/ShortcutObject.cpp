#include "ShortcutObject.h"

bool ShortcutObject::serialize(shared_ptr<MessageDataBuffer> output) {
	return Shortcut::serialize(output);
}

bool ShortcutObject::deserialize(shared_ptr<MessageDataBuffer> input) {
	return Shortcut::deserialize(input);
}
