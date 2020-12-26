#ifndef PRISMINFORMATION_H
#define PRISMINFORMATION_H

#include "NetworkType.h"


class PrismInformation : public NetworkType {
public:
	// Constructor
	PrismInformation() {};
	// Copy constructor
	PrismInformation(const PrismInformation& other) = default;

	// Copy operator
	PrismInformation& operator=(const PrismInformation& other) = default;
	// Destructor
	~PrismInformation() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 1525;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int placementDate = 0;
	int rewardTokenCount = 0;
	int nextVulnerabilityDate = 0;
	int state = 1;
	int type_id = 0;
};

#endif