#ifndef OBJECTEFFECTSTRING_H
#define OBJECTEFFECTSTRING_H

#include "ObjectEffect.h"


class ObjectEffectString : public ObjectEffect {
public:
	// Constructor
	ObjectEffectString() {};
	// Copy constructor
	ObjectEffectString(const ObjectEffectString& other) = default;

	// Copy operator
	ObjectEffectString& operator=(const ObjectEffectString& other) = default;
	// Destructor
	~ObjectEffectString() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 2778;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	string value;
};

#endif