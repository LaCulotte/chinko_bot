#ifndef TAXCOLLECTORSTATICINFORMATIONS_H
#define TAXCOLLECTORSTATICINFORMATIONS_H

#include "NetworkType.h"

#include "GuildInformations.h"

class TaxCollectorStaticInformations : public NetworkType {
public:
	// Constructor
	TaxCollectorStaticInformations() {};
	// Copy constructor
	TaxCollectorStaticInformations(const TaxCollectorStaticInformations& other) = default;

	// Copy operator
	TaxCollectorStaticInformations& operator=(const TaxCollectorStaticInformations& other) = default;
	// Destructor
	~TaxCollectorStaticInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 2842;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	GuildInformations guildIdentity;
	int lastNameId = 0;
	int firstNameId = 0;
};

#endif