#ifndef ALLIANCEPRISMINFORMATION_H
#define ALLIANCEPRISMINFORMATION_H

#include "PrismInformation.h"

#include "AllianceInformations.h"

class AlliancePrismInformation : public PrismInformation {
public:
	// Constructor
	AlliancePrismInformation() {};
	// Copy constructor
	AlliancePrismInformation(const AlliancePrismInformation& other) = default;

	// Copy operator
	AlliancePrismInformation& operator=(const AlliancePrismInformation& other) = default;
	// Destructor
	~AlliancePrismInformation() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 5996;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	AllianceInformations alliance;
};

#endif