#ifndef SHORTCUTSPELL_H
#define SHORTCUTSPELL_H

#include "Shortcut.h"


class ShortcutSpell : public Shortcut {
public:
	// Constructor
	ShortcutSpell() {};
	// Copy constructor
	ShortcutSpell(const ShortcutSpell& other) = default;

	// Copy operator
	ShortcutSpell& operator=(const ShortcutSpell& other) = default;
	// Destructor
	~ShortcutSpell() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 571;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int spellId = 0;
};

#endif