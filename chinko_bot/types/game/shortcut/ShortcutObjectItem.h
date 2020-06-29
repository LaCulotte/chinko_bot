#ifndef SHORTCUTOBJECTITEM_H
#define SHORTCUTOBJECTITEM_H

#include "ShortcutObject.h"

class ShortcutObjectItem : public ShortcutObject {
public: 
	// Constructor
	ShortcutObjectItem() {};
	// Constructor with slot, itemUID and itemGID initialization
	ShortcutObjectItem(int slot, int itemUID, int itemGID) : ShortcutObject(slot) { this->itemUID = itemUID; this->itemGID = itemGID; };
	// Copy constructor
	ShortcutObjectItem(const ShortcutObjectItem& other) = default;

	// Copy operator
	ShortcutObjectItem& operator=(const ShortcutObjectItem& other) = default;
	// Destructor
	~ShortcutObjectItem() = default;

	// Returns the type's id
	virtual unsigned int getId() { return typeId; };
	// Type's id
	static const unsigned int typeId = 371;
	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int itemUID;
	int itemGID;

};

#endif