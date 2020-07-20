#ifndef INTERACTIVEELEMENTWITHAGEBONUS_H
#define INTERACTIVEELEMENTWITHAGEBONUS_H

#include "InteractiveElement.h"


class InteractiveElementWithAgeBonus : public InteractiveElement {
public:
	// Constructor
	InteractiveElementWithAgeBonus() {};
	// Copy constructor
	InteractiveElementWithAgeBonus(const InteractiveElementWithAgeBonus& other) = default;

	// Copy operator
	InteractiveElementWithAgeBonus& operator=(const InteractiveElementWithAgeBonus& other) = default;
	// Destructor
	~InteractiveElementWithAgeBonus() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 398;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int ageBonus = 0;
};

#endif