#ifndef HOUSEGUILDEDINFORMATIONS_H
#define HOUSEGUILDEDINFORMATIONS_H

#include "HouseInstanceInformations.h"

#include "GuildInformations.h"

class HouseGuildedInformations : public HouseInstanceInformations {
public:
	// Constructor
	HouseGuildedInformations() {};
	// Copy constructor
	HouseGuildedInformations(const HouseGuildedInformations& other) = default;

	// Copy operator
	HouseGuildedInformations& operator=(const HouseGuildedInformations& other) = default;
	// Destructor
	~HouseGuildedInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 512;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	GuildInformations guildInfo;
};

#endif