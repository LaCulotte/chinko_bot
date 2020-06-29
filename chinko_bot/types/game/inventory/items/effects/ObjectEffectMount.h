#ifndef OBJECTEFFECTMOUNT_H
#define OBJECTEFFECTMOUNT_H

#include "ObjectEffect.h"
#include "ObjectEffectInteger.h"

class ObjectEffectMount : public ObjectEffect {
public: 
	// Constructor
	ObjectEffectMount() {};
	// Constructor with actionId initialization
	ObjectEffectMount(int actionId) : ObjectEffect(actionId) {};
	// Copy constructor
	ObjectEffectMount(const ObjectEffectMount& other) = default;

	// Copy operator
	ObjectEffectMount& operator=(const ObjectEffectMount& other) = default;
	// Destructor
	~ObjectEffectMount() = default;

	// Returns the type's id
	virtual unsigned int getId() { return typeId; };
	// Type's id
	static const unsigned int typeId = 179;	
	
	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	bool sex;
	bool ridable;
	bool feconded;
	bool isFecondationReady;
	
	uint64_t id;
	uint64_t expirationDate;
	int model;
	
	string name;
	string owner;
	
	int level;
	int reproductionCount;

	vector<ObjectEffectInteger> effects;
	vector<int> capacities;

};

#endif