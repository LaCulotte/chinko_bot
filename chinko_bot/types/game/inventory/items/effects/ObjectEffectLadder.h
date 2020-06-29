#ifndef OBJECTEFFECTLADDER_H
#define OBJECTEFFECTLADDER_H

#include "ObjectEffect.h"

class ObjectEffectLadder : public ObjectEffect {
public: 
	// Constructor
	ObjectEffectLadder() {};
	// Constructor with actionId and monsterCount initialization
	ObjectEffectLadder(int actionId, int monsterCount) : ObjectEffect(actionId) { this->monsterCount = monsterCount; };
	// Copy constructor
	ObjectEffectLadder(const ObjectEffectLadder& other) = default;

	// Copy operator
	ObjectEffectLadder& operator=(const ObjectEffectLadder& other) = default;
	// Destructor
	~ObjectEffectLadder() = default;

	// Returns the type's id
	virtual unsigned int getId() { return typeId; };
	// Type's id
	static const unsigned int typeId = 81;	
	
	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int monsterCount;

};

#endif