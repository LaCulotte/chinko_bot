#ifndef OBJECTITEMQUANTITY_H
#define OBJECTITEMQUANTITY_H

#include "Item.h"


class ObjectItemQuantity : public Item {
public:
	// Constructor
	ObjectItemQuantity() {};
	// Copy constructor
	ObjectItemQuantity(const ObjectItemQuantity& other) = default;

	// Copy operator
	ObjectItemQuantity& operator=(const ObjectItemQuantity& other) = default;
	// Destructor
	~ObjectItemQuantity() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 5989;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int quantity = 0;
	int objectUID = 0;
};

#endif