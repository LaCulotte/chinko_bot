#ifndef FIGHTALLIANCETEAMINFORMATIONS_H
#define FIGHTALLIANCETEAMINFORMATIONS_H

#include "FightTeamInformations.h"


class FightAllianceTeamInformations : public FightTeamInformations {
public:
	// Constructor
	FightAllianceTeamInformations() {};
	// Copy constructor
	FightAllianceTeamInformations(const FightAllianceTeamInformations& other) = default;

	// Copy operator
	FightAllianceTeamInformations& operator=(const FightAllianceTeamInformations& other) = default;
	// Destructor
	~FightAllianceTeamInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 439;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int relation = 0;
};

#endif