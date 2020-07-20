#ifndef SHORTCUTSMILEY_H
#define SHORTCUTSMILEY_H

#include "Shortcut.h"


class ShortcutSmiley : public Shortcut {
public:
	// Constructor
	ShortcutSmiley() {};
	// Copy constructor
	ShortcutSmiley(const ShortcutSmiley& other) = default;

	// Copy operator
	ShortcutSmiley& operator=(const ShortcutSmiley& other) = default;
	// Destructor
	~ShortcutSmiley() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 388;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int smileyId = 0;
};

#endif