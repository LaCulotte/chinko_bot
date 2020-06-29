#ifndef OBJECTEFFECTSTRING_H
#define OBJECTEFFECTSTRING_H

#include "ObjectEffect.h"

class ObjectEffectString : public ObjectEffect {
public: 
	// Constructor
	ObjectEffectString() {};
	// Constructor with actionId and value initialization
	ObjectEffectString(int actionId, string value) : ObjectEffect(actionId) { this->value = value; };
	// Copy constructor
	ObjectEffectString(const ObjectEffectString& other) = default;

	// Copy operator
	ObjectEffectString& operator=(const ObjectEffectString& other) = default;
	// Destructor
	~ObjectEffectString() = default;

	// Returns the type's id
	virtual unsigned int getId() { return typeId; };
	// Type's id
	static const unsigned int typeId = 74;	
	
	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	string value;

};

#endif