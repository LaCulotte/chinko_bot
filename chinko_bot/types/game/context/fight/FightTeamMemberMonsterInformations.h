#ifndef FIGHTTEAMMEMBERMONSTERINFORMATIONS_H
#define FIGHTTEAMMEMBERMONSTERINFORMATIONS_H

#include "FightTeamMemberInformations.h"


class FightTeamMemberMonsterInformations : public FightTeamMemberInformations {
public:
	// Constructor
	FightTeamMemberMonsterInformations() {};
	// Copy constructor
	FightTeamMemberMonsterInformations(const FightTeamMemberMonsterInformations& other) = default;

	// Copy operator
	FightTeamMemberMonsterInformations& operator=(const FightTeamMemberMonsterInformations& other) = default;
	// Destructor
	~FightTeamMemberMonsterInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 8154;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int grade = 0;
	int monsterId = 0;
};

#endif