#ifndef OBJECTEFFECT_H
#define OBJECTEFFECT_H

#include "NetworkType.h"


class ObjectEffect : public NetworkType {
public:
	// Constructor
	ObjectEffect() {};
	// Copy constructor
	ObjectEffect(const ObjectEffect& other) = default;

	// Copy operator
	ObjectEffect& operator=(const ObjectEffect& other) = default;
	// Destructor
	~ObjectEffect() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 6577;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int actionId = 0;
};

#endif