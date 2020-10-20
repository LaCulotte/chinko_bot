#ifndef SKILLACTIONDESCRIPTION_H
#define SKILLACTIONDESCRIPTION_H

#include "NetworkType.h"


class SkillActionDescription : public NetworkType {
public:
	// Constructor
	SkillActionDescription() {};
	// Copy constructor
	SkillActionDescription(const SkillActionDescription& other) = default;

	// Copy operator
	SkillActionDescription& operator=(const SkillActionDescription& other) = default;
	// Destructor
	~SkillActionDescription() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 6637;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int skillId = 0;
};

#endif