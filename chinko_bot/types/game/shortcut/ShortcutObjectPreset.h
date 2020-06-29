#ifndef SHORTCUTOBJECTPRESET_H
#define SHORTCUTOBJECTPRESET_H

#include "ShortcutObject.h"

class ShortcutObjectPreset : public ShortcutObject {
public: 
	// Constructor
	ShortcutObjectPreset() {};
	// Constructor with slot and presetId initialization
	ShortcutObjectPreset(int slot, int presetId) : ShortcutObject(slot) { this->presetId = presetId; };
	// Copy constructor
	ShortcutObjectPreset(const ShortcutObjectPreset& other) = default;

	// Copy operator
	ShortcutObjectPreset& operator=(const ShortcutObjectPreset& other) = default;
	// Destructor
	~ShortcutObjectPreset() = default;

	// Returns the type's id
	virtual unsigned int getId() { return typeId; };
	// Type's id
	static const unsigned int typeId = 370;
	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int presetId;

};

#endif