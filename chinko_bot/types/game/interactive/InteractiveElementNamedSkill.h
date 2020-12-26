#ifndef INTERACTIVEELEMENTNAMEDSKILL_H
#define INTERACTIVEELEMENTNAMEDSKILL_H

#include "InteractiveElementSkill.h"


class InteractiveElementNamedSkill : public InteractiveElementSkill {
public:
	// Constructor
	InteractiveElementNamedSkill() {};
	// Copy constructor
	InteractiveElementNamedSkill(const InteractiveElementNamedSkill& other) = default;

	// Copy operator
	InteractiveElementNamedSkill& operator=(const InteractiveElementNamedSkill& other) = default;
	// Destructor
	~InteractiveElementNamedSkill() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 7588;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int nameId = 0;
};

#endif