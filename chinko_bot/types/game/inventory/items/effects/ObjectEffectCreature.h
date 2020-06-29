#ifndef OBJECTEFFECTCREATURE_H
#define OBJECTEFFECTCREATURE_H

#include "ObjectEffect.h"

class ObjectEffectCreature : public ObjectEffect {
public: 
	// Constructor
	ObjectEffectCreature() {};
	// Constructor with monsterFamilyId initialization
	ObjectEffectCreature(int actionId, int monsterFamilyId) : ObjectEffect(actionId) { this->monsterFamilyId = monsterFamilyId; };
	// Copy constructor
	ObjectEffectCreature(const ObjectEffectCreature& other) = default;

	// Copy operator
	ObjectEffectCreature& operator=(const ObjectEffectCreature& other) = default;
	// Destructor
	~ObjectEffectCreature() = default;

	// Returns the type's id
	virtual unsigned int getId() { return typeId; };
	// Type's id
	static const unsigned int typeId = 71;
		
	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int monsterFamilyId;

};

#endif