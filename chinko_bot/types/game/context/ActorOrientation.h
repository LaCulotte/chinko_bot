#ifndef ACTORORIENTATION_H
#define ACTORORIENTATION_H

#include "NetworkType.h"


class ActorOrientation : public NetworkType {
public:
	// Constructor
	ActorOrientation() {};
	// Copy constructor
	ActorOrientation(const ActorOrientation& other) = default;

	// Copy operator
	ActorOrientation& operator=(const ActorOrientation& other) = default;
	// Destructor
	~ActorOrientation() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 8097;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int direction = 1;
	double id = 0;
};

#endif