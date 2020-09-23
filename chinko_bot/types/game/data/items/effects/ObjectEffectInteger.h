#ifndef OBJECTEFFECTINTEGER_H
#define OBJECTEFFECTINTEGER_H

#include "ObjectEffect.h"


class ObjectEffectInteger : public ObjectEffect {
public:
	// Constructor
	ObjectEffectInteger() {};
	// Copy constructor
	ObjectEffectInteger(const ObjectEffectInteger& other) = default;

	// Copy operator
	ObjectEffectInteger& operator=(const ObjectEffectInteger& other) = default;
	// Destructor
	~ObjectEffectInteger() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 9369;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int value = 0;
};

#endif