#ifndef OBJECTEFFECTMINMAX_H
#define OBJECTEFFECTMINMAX_H

#include "ObjectEffect.h"


class ObjectEffectMinMax : public ObjectEffect {
public:
	// Constructor
	ObjectEffectMinMax() {};
	// Copy constructor
	ObjectEffectMinMax(const ObjectEffectMinMax& other) = default;

	// Copy operator
	ObjectEffectMinMax& operator=(const ObjectEffectMinMax& other) = default;
	// Destructor
	~ObjectEffectMinMax() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 82;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int max = 0;
	int min = 0;
};

#endif