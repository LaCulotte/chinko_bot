#ifndef SPELLITEM_H
#define SPELLITEM_H

#include "Item.h"

class SpellItem : public Item {
public: 
	// Constructor
	SpellItem() {};
	// Constructor with spellId and spellLevel initialization
	SpellItem(int spellId, int spellLevel) { this->spellId = spellId; this->spellLevel = spellLevel; };
	// Copy constructor
	SpellItem(const SpellItem& other) = default;

	// Copy operator
	SpellItem& operator=(const SpellItem& other) = default;
	// Destructor
	~SpellItem() = default;

	// Returns the type's id
	virtual unsigned int getId() { return typeId; };
	// Type's id
	static const unsigned int typeId = 49;
	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int spellId;
	int spellLevel;

};

#endif