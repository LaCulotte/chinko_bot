#ifndef SHORTCUTOBJECT_H
#define SHORTCUTOBJECT_H

#include "Shortcut.h"


class ShortcutObject : public Shortcut {
public:
	// Constructor
	ShortcutObject() {};
	// Copy constructor
	ShortcutObject(const ShortcutObject& other) = default;

	// Copy operator
	ShortcutObject& operator=(const ShortcutObject& other) = default;
	// Destructor
	~ShortcutObject() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 5832;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override{ return true; };
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override{ return true; };

};

#endif