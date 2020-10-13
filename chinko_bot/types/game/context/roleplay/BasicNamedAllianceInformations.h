#ifndef BASICNAMEDALLIANCEINFORMATIONS_H
#define BASICNAMEDALLIANCEINFORMATIONS_H

#include "BasicAllianceInformations.h"


class BasicNamedAllianceInformations : public BasicAllianceInformations {
public:
	// Constructor
	BasicNamedAllianceInformations() {};
	// Copy constructor
	BasicNamedAllianceInformations(const BasicNamedAllianceInformations& other) = default;

	// Copy operator
	BasicNamedAllianceInformations& operator=(const BasicNamedAllianceInformations& other) = default;
	// Destructor
	~BasicNamedAllianceInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 3494;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	string allianceName;
};

#endif