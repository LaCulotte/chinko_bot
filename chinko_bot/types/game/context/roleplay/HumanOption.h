#ifndef HUMANOPTION_H
#define HUMANOPTION_H

#include "NetworkType.h"


class HumanOption : public NetworkType {
public:
	// Constructor
	HumanOption() {};
	// Copy constructor
	HumanOption(const HumanOption& other) = default;

	// Copy operator
	HumanOption& operator=(const HumanOption& other) = default;
	// Destructor
	~HumanOption() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 4884;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override { return true; };
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override { return true; };

};

#endif