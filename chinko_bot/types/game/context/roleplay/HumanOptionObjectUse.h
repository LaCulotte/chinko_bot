#ifndef HUMANOPTIONOBJECTUSE_H
#define HUMANOPTIONOBJECTUSE_H

#include "HumanOption.h"


class HumanOptionObjectUse : public HumanOption {
public:
	// Constructor
	HumanOptionObjectUse() {};
	// Copy constructor
	HumanOptionObjectUse(const HumanOptionObjectUse& other) = default;

	// Copy operator
	HumanOptionObjectUse& operator=(const HumanOptionObjectUse& other) = default;
	// Destructor
	~HumanOptionObjectUse() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 2440;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int objectGID = 0;
	double delayEndTime = 0;
	int delayTypeId = 0;
};

#endif