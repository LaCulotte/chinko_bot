#ifndef SHORTCUTSPELL_H
#define SHORTCUTSPELL_H

#include "Shortcut.h"

class ShortcutSpell : public Shortcut {
public: 
	// Constructor
	ShortcutSpell() {};
	// Constructor with slot and spellId initialization
	ShortcutSpell(int slot, int spellId) : Shortcut(slot) { this->spellId = spellId; };
	// Copy constructor
	ShortcutSpell(const ShortcutSpell& other) = default;

	// Copy operator
	ShortcutSpell& operator=(const ShortcutSpell& other) = default;
	// Destructor
	~ShortcutSpell() = default;

	// Returns the type's id
	virtual unsigned int getId() { return typeId; };
	// Type's id
	static const unsigned int typeId = 368;
	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int spellId;

};

#endif