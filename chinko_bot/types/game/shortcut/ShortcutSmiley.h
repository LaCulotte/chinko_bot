#ifndef SHORTCUTSMILEY_H
#define SHORTCUTSMILEY_H

#include "Shortcut.h"

class ShortcutSmiley : public Shortcut {
public: 
	// Constructor
	ShortcutSmiley() {};
	// Constructor with slot and smileyId initialization
	ShortcutSmiley(int slot, int smileyId) : Shortcut(slot) { this->smileyId = smileyId; };
	// Copy constructor
	ShortcutSmiley(const ShortcutSmiley& other) = default;

	// Copy operator
	ShortcutSmiley& operator=(const ShortcutSmiley& other) = default;
	// Destructor
	~ShortcutSmiley() = default;

	// Returns the type's id
	virtual unsigned int getId() { return typeId; };
	// Type's id
	static const unsigned int typeId = 388;
	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int smileyId;

};

#endif