#ifndef ALLIANCEINSIDERPRISMINFORMATION_H
#define ALLIANCEINSIDERPRISMINFORMATION_H

#include "PrismInformation.h"

#include "ObjectItem.h"

class AllianceInsiderPrismInformation : public PrismInformation {
public:
	// Constructor
	AllianceInsiderPrismInformation() {};
	// Copy constructor
	AllianceInsiderPrismInformation(const AllianceInsiderPrismInformation& other) = default;

	// Copy operator
	AllianceInsiderPrismInformation& operator=(const AllianceInsiderPrismInformation& other) = default;
	// Destructor
	~AllianceInsiderPrismInformation() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 9949;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<ObjectItem> modulesObjects;
	int lastTimeSlotModificationAuthorGuildId = 0;
	string lastTimeSlotModificationAuthorName;
	uint64_t lastTimeSlotModificationAuthorId = 0;
	int lastTimeSlotModificationDate = 0;
};

#endif