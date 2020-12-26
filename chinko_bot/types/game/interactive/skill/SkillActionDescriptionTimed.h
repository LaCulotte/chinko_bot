#ifndef SKILLACTIONDESCRIPTIONTIMED_H
#define SKILLACTIONDESCRIPTIONTIMED_H

#include "SkillActionDescription.h"


class SkillActionDescriptionTimed : public SkillActionDescription {
public:
	// Constructor
	SkillActionDescriptionTimed() {};
	// Copy constructor
	SkillActionDescriptionTimed(const SkillActionDescriptionTimed& other) = default;

	// Copy operator
	SkillActionDescriptionTimed& operator=(const SkillActionDescriptionTimed& other) = default;
	// Destructor
	~SkillActionDescriptionTimed() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 7758;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int time = 0;
};

#endif