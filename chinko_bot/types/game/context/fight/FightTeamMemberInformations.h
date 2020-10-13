#ifndef FIGHTTEAMMEMBERINFORMATIONS_H
#define FIGHTTEAMMEMBERINFORMATIONS_H

#include "NetworkType.h"


class FightTeamMemberInformations : public NetworkType {
public:
	// Constructor
	FightTeamMemberInformations() {};
	// Copy constructor
	FightTeamMemberInformations(const FightTeamMemberInformations& other) = default;

	// Copy operator
	FightTeamMemberInformations& operator=(const FightTeamMemberInformations& other) = default;
	// Destructor
	~FightTeamMemberInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 9464;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	double id = 0;
};

#endif