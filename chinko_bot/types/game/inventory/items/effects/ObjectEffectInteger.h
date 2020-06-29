#ifndef OBJECTEFFECTINTEGER_H
#define OBJECTEFFECTINTEGER_H

#include "ObjectEffect.h"

class ObjectEffectInteger : public ObjectEffect {
public: 
	// Constructor
	ObjectEffectInteger() {};
	// Constructor with value initialization
	ObjectEffectInteger(int actionId, int value) : ObjectEffect(actionId) { this->value = value; };
	// Copy constructor
	ObjectEffectInteger(const ObjectEffectInteger& other) = default;

	// Copy operator
	ObjectEffectInteger& operator=(const ObjectEffectInteger& other) = default;
	// Destructor
	~ObjectEffectInteger() = default;

	// Returns the type's id
	virtual unsigned int getId() { return typeId; };
	// Type's id
	static const unsigned int typeId = 70;	
	
	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int value;

};

#endif