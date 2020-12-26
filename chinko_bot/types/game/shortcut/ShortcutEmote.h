#ifndef SHORTCUTEMOTE_H
#define SHORTCUTEMOTE_H

#include "Shortcut.h"


class ShortcutEmote : public Shortcut {
public:
	// Constructor
	ShortcutEmote() {};
	// Copy constructor
	ShortcutEmote(const ShortcutEmote& other) = default;

	// Copy operator
	ShortcutEmote& operator=(const ShortcutEmote& other) = default;
	// Destructor
	~ShortcutEmote() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 3412;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int emoteId = 0;
};

#endif