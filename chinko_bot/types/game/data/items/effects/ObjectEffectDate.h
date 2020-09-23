#ifndef OBJECTEFFECTDATE_H
#define OBJECTEFFECTDATE_H

#include "ObjectEffect.h"


class ObjectEffectDate : public ObjectEffect {
public:
	// Constructor
	ObjectEffectDate() {};
	// Copy constructor
	ObjectEffectDate(const ObjectEffectDate& other) = default;

	// Copy operator
	ObjectEffectDate& operator=(const ObjectEffectDate& other) = default;
	// Destructor
	~ObjectEffectDate() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 2036;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int minute = 0;
	int hour = 0;
	int day = 0;
	int month = 0;
	int year = 0;
};

#endif