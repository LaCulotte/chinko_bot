#ifndef SHORTCUTOBJECTIDOLSPRESET_H
#define SHORTCUTOBJECTIDOLSPRESET_H

#include "ShortcutObject.h"


class ShortcutObjectIdolsPreset : public ShortcutObject {
public:
	// Constructor
	ShortcutObjectIdolsPreset() {};
	// Copy constructor
	ShortcutObjectIdolsPreset(const ShortcutObjectIdolsPreset& other) = default;

	// Copy operator
	ShortcutObjectIdolsPreset& operator=(const ShortcutObjectIdolsPreset& other) = default;
	// Destructor
	~ShortcutObjectIdolsPreset() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 5835;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int presetId = 0;
};

#endif