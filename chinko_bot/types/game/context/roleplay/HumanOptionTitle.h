#ifndef HUMANOPTIONTITLE_H
#define HUMANOPTIONTITLE_H

#include "HumanOption.h"


class HumanOptionTitle : public HumanOption {
public:
	// Constructor
	HumanOptionTitle() {};
	// Copy constructor
	HumanOptionTitle(const HumanOptionTitle& other) = default;

	// Copy operator
	HumanOptionTitle& operator=(const HumanOptionTitle& other) = default;
	// Destructor
	~HumanOptionTitle() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 7090;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	string titleParam;
	int titleId = 0;
};

#endif