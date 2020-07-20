#ifndef OBJECTEFFECTDURATION_H
#define OBJECTEFFECTDURATION_H

#include "ObjectEffect.h"


class ObjectEffectDuration : public ObjectEffect {
public:
	// Constructor
	ObjectEffectDuration() {};
	// Copy constructor
	ObjectEffectDuration(const ObjectEffectDuration& other) = default;

	// Copy operator
	ObjectEffectDuration& operator=(const ObjectEffectDuration& other) = default;
	// Destructor
	~ObjectEffectDuration() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 75;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int minutes = 0;
	int hours = 0;
	int days = 0;
};

#endif