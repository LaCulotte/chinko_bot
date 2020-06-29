#ifndef OBJECTEFFECTMINMAX_H
#define OBJECTEFFECTMINMAX_H

#include "ObjectEffect.h"

class ObjectEffectMinMax : public ObjectEffect {
public: 
	// Constructor
	ObjectEffectMinMax() {};
	// Constructor with actionId, min and max initialization
	ObjectEffectMinMax(int actionId, int min, int max) : ObjectEffect(actionId) { this->min = min; this->max = max; };
	// Copy constructor
	ObjectEffectMinMax(const ObjectEffectMinMax& other) = default;

	// Copy operator
	ObjectEffectMinMax& operator=(const ObjectEffectMinMax& other) = default;
	// Destructor
	~ObjectEffectMinMax() = default;

	// Returns the type's id
	virtual unsigned int getId() { return typeId; };
	// Type's id
	static const unsigned int typeId = 82;	
	
	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int min;
	int max;

};

#endif