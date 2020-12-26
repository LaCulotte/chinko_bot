#ifndef HUMANOPTIONALLIANCE_H
#define HUMANOPTIONALLIANCE_H

#include "HumanOption.h"

#include "AllianceInformations.h"

class HumanOptionAlliance : public HumanOption {
public:
	// Constructor
	HumanOptionAlliance() {};
	// Copy constructor
	HumanOptionAlliance(const HumanOptionAlliance& other) = default;

	// Copy operator
	HumanOptionAlliance& operator=(const HumanOptionAlliance& other) = default;
	// Destructor
	~HumanOptionAlliance() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 4941;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int aggressable = 0;
	AllianceInformations allianceInformations;
};

#endif