#ifndef SHORTCUTOBJECTIDOLSPRESET_H
#define SHORTCUTOBJECTIDOLSPRESET_H

#include "ShortcutObject.h"

class ShortcutObjectIdolsPreset : public ShortcutObject {
public: 
	// Constructor
	ShortcutObjectIdolsPreset() {};
	// Constructor with slot and presetId initialization
	ShortcutObjectIdolsPreset(int slot, int presetId) : ShortcutObject(slot) { this->presetId = presetId; };
	// Copy constructor
	ShortcutObjectIdolsPreset(const ShortcutObjectIdolsPreset& other) = default;

	// Copy operator
	ShortcutObjectIdolsPreset& operator=(const ShortcutObjectIdolsPreset& other) = default;
	// Destructor
	~ShortcutObjectIdolsPreset() = default;

	// Returns the type's id
	virtual unsigned int getId() { return typeId; };
	// Type's id
	static const unsigned int typeId = 492;
	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int presetId;

};

#endif