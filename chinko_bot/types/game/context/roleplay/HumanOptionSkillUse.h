#ifndef HUMANOPTIONSKILLUSE_H
#define HUMANOPTIONSKILLUSE_H

#include "HumanOption.h"


class HumanOptionSkillUse : public HumanOption {
public:
	// Constructor
	HumanOptionSkillUse() {};
	// Copy constructor
	HumanOptionSkillUse(const HumanOptionSkillUse& other) = default;

	// Copy operator
	HumanOptionSkillUse& operator=(const HumanOptionSkillUse& other) = default;
	// Destructor
	~HumanOptionSkillUse() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 4888;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	double skillEndTime = 0;
	int skillId = 0;
	int elementId = 0;
};

#endif