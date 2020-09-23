#ifndef OBJECTEFFECTCREATURE_H
#define OBJECTEFFECTCREATURE_H

#include "ObjectEffect.h"


class ObjectEffectCreature : public ObjectEffect {
public:
	// Constructor
	ObjectEffectCreature() {};
	// Copy constructor
	ObjectEffectCreature(const ObjectEffectCreature& other) = default;

	// Copy operator
	ObjectEffectCreature& operator=(const ObjectEffectCreature& other) = default;
	// Destructor
	~ObjectEffectCreature() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 9295;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int monsterFamilyId = 0;
};

#endif