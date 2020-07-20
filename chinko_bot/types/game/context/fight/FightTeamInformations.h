#ifndef FIGHTTEAMINFORMATIONS_H
#define FIGHTTEAMINFORMATIONS_H

#include "AbstractFightTeamInformations.h"

#include "FightTeamMemberInformations.h"

#include "NetworkTypeHandler.h"

class FightTeamInformations : public AbstractFightTeamInformations {
public:
	// Constructor
	FightTeamInformations() {};
	// Copy constructor
	FightTeamInformations(const FightTeamInformations& other) = default;

	// Copy operator
	FightTeamInformations& operator=(const FightTeamInformations& other) = default;
	// Destructor
	~FightTeamInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 33;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<sp<FightTeamMemberInformations>> teamMembers;
};

#endif