#ifndef OBJECTEFFECTMOUNT_H
#define OBJECTEFFECTMOUNT_H

#include "ObjectEffect.h"

#include "ObjectEffectInteger.h"

class ObjectEffectMount : public ObjectEffect {
public:
	// Constructor
	ObjectEffectMount() {};
	// Copy constructor
	ObjectEffectMount(const ObjectEffectMount& other) = default;

	// Copy operator
	ObjectEffectMount& operator=(const ObjectEffectMount& other) = default;
	// Destructor
	~ObjectEffectMount() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 179;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<int> capacities;
	uint64_t id = 0;
	uint64_t expirationDate = 0;
	int model = 0;
	int reproductionCountMax = 0;
	string name;
	int level = 0;
	string owner;
	bool isFeconded = false;
	bool sex = false;
	bool isFecondationReady = false;
	bool isRideable = false;
	int reproductionCount = 0;
	vector<ObjectEffectInteger> effects;
};

#endif