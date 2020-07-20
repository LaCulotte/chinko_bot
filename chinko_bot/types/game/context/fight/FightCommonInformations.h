#ifndef FIGHTCOMMONINFORMATIONS_H
#define FIGHTCOMMONINFORMATIONS_H

#include "NetworkType.h"

#include "FightOptionsInformations.h"
#include "FightTeamInformations.h"

#include "NetworkTypeHandler.h"

class FightCommonInformations : public NetworkType {
public:
	// Constructor
	FightCommonInformations() {};
	// Copy constructor
	FightCommonInformations(const FightCommonInformations& other) = default;

	// Copy operator
	FightCommonInformations& operator=(const FightCommonInformations& other) = default;
	// Destructor
	~FightCommonInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 43;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<FightOptionsInformations> fightTeamsOptions;
	vector<int> fightTeamsPositions;
	vector<sp<FightTeamInformations>> fightTeams;
	int fightType = 0;
	int fightId = 0;
};

#endif