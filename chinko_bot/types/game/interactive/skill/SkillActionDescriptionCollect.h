#ifndef SKILLACTIONDESCRIPTIONCOLLECT_H
#define SKILLACTIONDESCRIPTIONCOLLECT_H

#include "SkillActionDescriptionTimed.h"


class SkillActionDescriptionCollect : public SkillActionDescriptionTimed {
public:
	// Constructor
	SkillActionDescriptionCollect() {};
	// Copy constructor
	SkillActionDescriptionCollect(const SkillActionDescriptionCollect& other) = default;

	// Copy operator
	SkillActionDescriptionCollect& operator=(const SkillActionDescriptionCollect& other) = default;
	// Destructor
	~SkillActionDescriptionCollect() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 7961;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int max = 0;
	int min = 0;
};

#endif