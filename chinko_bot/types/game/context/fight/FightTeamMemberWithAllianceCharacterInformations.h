#ifndef FIGHTTEAMMEMBERWITHALLIANCECHARACTERINFORMATIONS_H
#define FIGHTTEAMMEMBERWITHALLIANCECHARACTERINFORMATIONS_H

#include "FightTeamMemberCharacterInformations.h"

#include "BasicAllianceInformations.h"

class FightTeamMemberWithAllianceCharacterInformations : public FightTeamMemberCharacterInformations {
public:
	// Constructor
	FightTeamMemberWithAllianceCharacterInformations() {};
	// Copy constructor
	FightTeamMemberWithAllianceCharacterInformations(const FightTeamMemberWithAllianceCharacterInformations& other) = default;

	// Copy operator
	FightTeamMemberWithAllianceCharacterInformations& operator=(const FightTeamMemberWithAllianceCharacterInformations& other) = default;
	// Destructor
	~FightTeamMemberWithAllianceCharacterInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 8004;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	BasicAllianceInformations allianceInfos;
};

#endif