#ifndef SKILLACTIONDESCRIPTIONCRAFT_H
#define SKILLACTIONDESCRIPTIONCRAFT_H

#include "SkillActionDescription.h"


class SkillActionDescriptionCraft : public SkillActionDescription {
public:
	// Constructor
	SkillActionDescriptionCraft() {};
	// Copy constructor
	SkillActionDescriptionCraft(const SkillActionDescriptionCraft& other) = default;

	// Copy operator
	SkillActionDescriptionCraft& operator=(const SkillActionDescriptionCraft& other) = default;
	// Destructor
	~SkillActionDescriptionCraft() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 6486;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int probability = 0;
};

#endif