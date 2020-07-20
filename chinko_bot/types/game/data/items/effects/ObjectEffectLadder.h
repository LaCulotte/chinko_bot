#ifndef OBJECTEFFECTLADDER_H
#define OBJECTEFFECTLADDER_H

#include "ObjectEffectCreature.h"


class ObjectEffectLadder : public ObjectEffectCreature {
public:
	// Constructor
	ObjectEffectLadder() {};
	// Copy constructor
	ObjectEffectLadder(const ObjectEffectLadder& other) = default;

	// Copy operator
	ObjectEffectLadder& operator=(const ObjectEffectLadder& other) = default;
	// Destructor
	~ObjectEffectLadder() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 81;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int monsterCount = 0;
};

#endif