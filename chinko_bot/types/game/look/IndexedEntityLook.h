#ifndef INDEXEDENTITYLOOK_H
#define INDEXEDENTITYLOOK_H

#include "NetworkType.h"

#include "EntityLook.h"

class IndexedEntityLook : public NetworkType {
public:
	// Constructor
	IndexedEntityLook() {};
	// Copy constructor
	IndexedEntityLook(const IndexedEntityLook& other) = default;

	// Copy operator
	IndexedEntityLook& operator=(const IndexedEntityLook& other) = default;
	// Destructor
	~IndexedEntityLook() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 8039;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int index = 0;
	EntityLook look;
};

#endif