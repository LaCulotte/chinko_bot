#ifndef ENTITYLOOK_H
#define ENTITYLOOK_H

#include "NetworkType.h"

#include "SubEntity.h"

class SubEntity;
class EntityLook : public NetworkType {
public:
	// Constructor
	EntityLook() {};
	// Copy constructor
	EntityLook(const EntityLook& other) = default;

	// Copy operator
	EntityLook& operator=(const EntityLook& other) = default;
	// Destructor
	~EntityLook() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 2892;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<SubEntity> subentities;
	vector<int> scales;
	vector<int> indexedColors;
	vector<int> skins;
	int bonesId = 0;
};

#endif