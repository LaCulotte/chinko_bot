#ifndef SUBENTITY_H
#define SUBENTITY_H

#include "NetworkType.h"

#include "EntityLook.h"

class EntityLook;
class SubEntity : public NetworkType {
public:
	// Constructor
	SubEntity() {};
	// Copy constructor
	SubEntity(const SubEntity& other) = default;

	// Copy operator
	SubEntity& operator=(const SubEntity& other) = default;
	// Destructor
	~SubEntity() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 4652;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	sp<EntityLook> subEntityLook;
	int bindingPointIndex = 0;
	int bindingPointCategory = 0;
};

#endif