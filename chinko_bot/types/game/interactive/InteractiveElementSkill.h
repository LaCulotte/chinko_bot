#ifndef INTERACTIVEELEMENTSKILL_H
#define INTERACTIVEELEMENTSKILL_H

#include "NetworkType.h"


class InteractiveElementSkill : public NetworkType {
public:
	// Constructor
	InteractiveElementSkill() {};
	// Copy constructor
	InteractiveElementSkill(const InteractiveElementSkill& other) = default;

	// Copy operator
	InteractiveElementSkill& operator=(const InteractiveElementSkill& other) = default;
	// Destructor
	~InteractiveElementSkill() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 219;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int skillInstanceUid = 0;
	int skillId = 0;
};

#endif