#ifndef ALLIANCEINFORMATIONS_H
#define ALLIANCEINFORMATIONS_H

#include "BasicNamedAllianceInformations.h"

#include "GuildEmblem.h"

class AllianceInformations : public BasicNamedAllianceInformations {
public:
	// Constructor
	AllianceInformations() {};
	// Copy constructor
	AllianceInformations(const AllianceInformations& other) = default;

	// Copy operator
	AllianceInformations& operator=(const AllianceInformations& other) = default;
	// Destructor
	~AllianceInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 417;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	GuildEmblem allianceEmblem;
};

#endif