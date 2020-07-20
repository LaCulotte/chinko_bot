#ifndef OBJECTITEM_H
#define OBJECTITEM_H

#include "Item.h"

#include "ObjectEffect.h"

#include "NetworkTypeHandler.h"

class ObjectItem : public Item {
public:
	// Constructor
	ObjectItem() {};
	// Copy constructor
	ObjectItem(const ObjectItem& other) = default;

	// Copy operator
	ObjectItem& operator=(const ObjectItem& other) = default;
	// Destructor
	~ObjectItem() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 37;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int quantity = 0;
	int objectUID = 0;
	vector<sp<ObjectEffect>> effects;
	int objectGID = 0;
	int position = 63;
};

#endif