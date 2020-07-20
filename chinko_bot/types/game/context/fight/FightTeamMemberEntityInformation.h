#ifndef FIGHTTEAMMEMBERENTITYINFORMATION_H
#define FIGHTTEAMMEMBERENTITYINFORMATION_H

#include "FightTeamMemberInformations.h"


class FightTeamMemberEntityInformation : public FightTeamMemberInformations {
public:
	// Constructor
	FightTeamMemberEntityInformation() {};
	// Copy constructor
	FightTeamMemberEntityInformation(const FightTeamMemberEntityInformation& other) = default;

	// Copy operator
	FightTeamMemberEntityInformation& operator=(const FightTeamMemberEntityInformation& other) = default;
	// Destructor
	~FightTeamMemberEntityInformation() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 549;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	double masterId = 0;
	int level = 0;
	int entityModelId = 0;
};

#endif