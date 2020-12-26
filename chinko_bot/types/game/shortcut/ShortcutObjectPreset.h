#ifndef SHORTCUTOBJECTPRESET_H
#define SHORTCUTOBJECTPRESET_H

#include "ShortcutObject.h"


class ShortcutObjectPreset : public ShortcutObject {
public:
	// Constructor
	ShortcutObjectPreset() {};
	// Copy constructor
	ShortcutObjectPreset(const ShortcutObjectPreset& other) = default;

	// Copy operator
	ShortcutObjectPreset& operator=(const ShortcutObjectPreset& other) = default;
	// Destructor
	~ShortcutObjectPreset() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 2425;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int presetId = 0;
};

#endif