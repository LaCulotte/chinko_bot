#ifndef SHORTCUTOBJECTITEM_H
#define SHORTCUTOBJECTITEM_H

#include "ShortcutObject.h"


class ShortcutObjectItem : public ShortcutObject {
public:
	// Constructor
	ShortcutObjectItem() {};
	// Copy constructor
	ShortcutObjectItem(const ShortcutObjectItem& other) = default;

	// Copy operator
	ShortcutObjectItem& operator=(const ShortcutObjectItem& other) = default;
	// Destructor
	~ShortcutObjectItem() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 371;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int itemGID = 0;
	int itemUID = 0;
};

#endif