#ifndef SPELLITEM_H
#define SPELLITEM_H

#include "Item.h"


class SpellItem : public Item {
public:
	// Constructor
	SpellItem() {};
	// Copy constructor
	SpellItem(const SpellItem& other) = default;

	// Copy operator
	SpellItem& operator=(const SpellItem& other) = default;
	// Destructor
	~SpellItem() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 7456;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int spellLevel = 0;
	int spellId = 0;
};

#endif