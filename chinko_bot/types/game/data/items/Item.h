#ifndef ITEM_H
#define ITEM_H

#include "NetworkType.h"


class Item : public NetworkType {
public:
	// Constructor
	Item() {};
	// Copy constructor
	Item(const Item& other) = default;

	// Copy operator
	Item& operator=(const Item& other) = default;
	// Destructor
	~Item() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 2786;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override { return true; };
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override { return true; };

};

#endif