#ifndef OBJECTEFFECTDATE_H
#define OBJECTEFFECTDATE_H

#include "ObjectEffect.h"

class ObjectEffectDate : public ObjectEffect {
public: 
	// Constructor
	ObjectEffectDate() {};
	// Constructor with actionId initialization
	ObjectEffectDate(int actionId) : ObjectEffect(actionId) {};
	// Copy constructor
	ObjectEffectDate(const ObjectEffectDate& other) = default;

	// Copy operator
	ObjectEffectDate& operator=(const ObjectEffectDate& other) = default;
	// Destructor
	~ObjectEffectDate() = default;

	// Returns the type's id
	virtual unsigned int getId() { return typeId; };
	// Type's id
	static const unsigned int typeId = 72;
	
	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int year;
	int month;
	int day;
	int hour;
	int minute;

};

#endif