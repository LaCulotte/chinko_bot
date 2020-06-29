#ifndef SHORTCUTEMOTE_H
#define SHORTCUTEMOTE_H

#include "Shortcut.h"

class ShortcutEmote : public Shortcut {
public: 
	// Constructor
	ShortcutEmote() {};
	// Constructor with slot and emoteId initialization
	ShortcutEmote(int slot, int emoteId) : Shortcut(slot) { this->emoteId = emoteId; };
	// Copy constructor
	ShortcutEmote(const ShortcutEmote& other) = default;

	// Copy operator
	ShortcutEmote& operator=(const ShortcutEmote& other) = default;
	// Destructor
	~ShortcutEmote() = default;

	// Returns the type's id
	virtual unsigned int getId() { return typeId; };
	// Type's id
	static const unsigned int typeId = 389;
	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int emoteId;

};

#endif