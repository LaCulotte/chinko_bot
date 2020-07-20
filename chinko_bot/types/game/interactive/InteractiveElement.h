#ifndef INTERACTIVEELEMENT_H
#define INTERACTIVEELEMENT_H

#include "NetworkType.h"

#include "InteractiveElementSkill.h"

#include "NetworkTypeHandler.h"

class InteractiveElement : public NetworkType {
public:
	// Constructor
	InteractiveElement() {};
	// Copy constructor
	InteractiveElement(const InteractiveElement& other) = default;

	// Copy operator
	InteractiveElement& operator=(const InteractiveElement& other) = default;
	// Destructor
	~InteractiveElement() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 80;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	bool onCurrentMap = false;
	vector<sp<InteractiveElementSkill>> disabledSkills;
	vector<sp<InteractiveElementSkill>> enabledSkills;
	int elementTypeId = 0;
	int elementId = 0;
};

#endif