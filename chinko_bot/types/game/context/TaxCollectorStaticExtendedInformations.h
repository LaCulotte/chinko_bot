#ifndef TAXCOLLECTORSTATICEXTENDEDINFORMATIONS_H
#define TAXCOLLECTORSTATICEXTENDEDINFORMATIONS_H

#include "TaxCollectorStaticInformations.h"

#include "AllianceInformations.h"

class TaxCollectorStaticExtendedInformations : public TaxCollectorStaticInformations {
public:
	// Constructor
	TaxCollectorStaticExtendedInformations() {};
	// Copy constructor
	TaxCollectorStaticExtendedInformations(const TaxCollectorStaticExtendedInformations& other) = default;

	// Copy operator
	TaxCollectorStaticExtendedInformations& operator=(const TaxCollectorStaticExtendedInformations& other) = default;
	// Destructor
	~TaxCollectorStaticExtendedInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 440;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	AllianceInformations allianceIdentity;
};

#endif