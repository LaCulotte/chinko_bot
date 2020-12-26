#ifndef BASICALLIANCEINFORMATIONS_H
#define BASICALLIANCEINFORMATIONS_H

#include "AbstractSocialGroupInfos.h"


class BasicAllianceInformations : public AbstractSocialGroupInfos {
public:
	// Constructor
	BasicAllianceInformations() {};
	// Copy constructor
	BasicAllianceInformations(const BasicAllianceInformations& other) = default;

	// Copy operator
	BasicAllianceInformations& operator=(const BasicAllianceInformations& other) = default;
	// Destructor
	~BasicAllianceInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 1115;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	string allianceTag;
	int allianceId = 0;
};

#endif