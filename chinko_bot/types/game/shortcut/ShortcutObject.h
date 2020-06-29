#ifndef SHORTCUTOBJECT_H
#define SHORTCUTOBJECT_H

#include "Shortcut.h"

class ShortcutObject : public Shortcut {
public: 
	// Constructor
	ShortcutObject() {};
	// Constructor with slot initialization
	ShortcutObject(int slot) : Shortcut(slot) {};
	// Copy constructor
	ShortcutObject(const ShortcutObject& other) = default;

	// Copy operator
	ShortcutObject& operator=(const ShortcutObject& other) = default;
	// Destructor
	~ShortcutObject() = default;

	// Returns the type's id
	virtual unsigned int getId() { return typeId; };
	// Type's id
	static const unsigned int typeId = 367;
	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;


};

#endif