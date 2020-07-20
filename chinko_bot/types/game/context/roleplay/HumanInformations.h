#ifndef HUMANINFORMATIONS_H
#define HUMANINFORMATIONS_H

#include "NetworkType.h"

#include "HumanOption.h"
#include "ActorRestrictionsInformations.h"

#include "NetworkTypeHandler.h"

class HumanInformations : public NetworkType {
public:
	// Constructor
	HumanInformations() {};
	// Copy constructor
	HumanInformations(const HumanInformations& other) = default;

	// Copy operator
	HumanInformations& operator=(const HumanInformations& other) = default;
	// Destructor
	~HumanInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 157;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<sp<HumanOption>> options;
	bool sex = false;
	ActorRestrictionsInformations restrictions;
};

#endif