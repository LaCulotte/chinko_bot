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

	// Returns the type's id
	virtual unsigned int getId() { return typeId; };
	// Type's id
	static const unsigned int typeId = 37;
	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int position;
	int objectGID;
	vector<sp<ObjectEffect>> effects;
	int objectUID;
	int quantity;

};

#endif