#ifndef FIGHTTEAMMEMBERCHARACTERINFORMATIONS_H
#define FIGHTTEAMMEMBERCHARACTERINFORMATIONS_H

#include "FightTeamMemberInformations.h"


class FightTeamMemberCharacterInformations : public FightTeamMemberInformations {
public:
	// Constructor
	FightTeamMemberCharacterInformations() {};
	// Copy constructor
	FightTeamMemberCharacterInformations(const FightTeamMemberCharacterInformations& other) = default;

	// Copy operator
	FightTeamMemberCharacterInformations& operator=(const FightTeamMemberCharacterInformations& other) = default;
	// Destructor
	~FightTeamMemberCharacterInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 314;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int level = 0;
	string name;
};

#endif