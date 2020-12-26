#ifndef FIGHTTEAMMEMBERTAXCOLLECTORINFORMATIONS_H
#define FIGHTTEAMMEMBERTAXCOLLECTORINFORMATIONS_H

#include "FightTeamMemberInformations.h"


class FightTeamMemberTaxCollectorInformations : public FightTeamMemberInformations {
public:
	// Constructor
	FightTeamMemberTaxCollectorInformations() {};
	// Copy constructor
	FightTeamMemberTaxCollectorInformations(const FightTeamMemberTaxCollectorInformations& other) = default;

	// Copy operator
	FightTeamMemberTaxCollectorInformations& operator=(const FightTeamMemberTaxCollectorInformations& other) = default;
	// Destructor
	~FightTeamMemberTaxCollectorInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 1174;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int level = 0;
	double uid = 0;
	int lastNameId = 0;
	int guildId = 0;
	int firstNameId = 0;
};

#endif