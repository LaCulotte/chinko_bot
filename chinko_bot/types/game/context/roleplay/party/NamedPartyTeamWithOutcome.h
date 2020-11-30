#ifndef NAMEDPARTYTEAMWITHOUTCOME_H
#define NAMEDPARTYTEAMWITHOUTCOME_H

#include "NetworkType.h"

#include "NamedPartyTeam.h"

class NamedPartyTeamWithOutcome : public NetworkType {
public:
	// Constructor
	NamedPartyTeamWithOutcome() {};
	// Copy constructor
	NamedPartyTeamWithOutcome(const NamedPartyTeamWithOutcome& other) = default;

	// Copy operator
	NamedPartyTeamWithOutcome& operator=(const NamedPartyTeamWithOutcome& other) = default;
	// Destructor
	~NamedPartyTeamWithOutcome() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 8522;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int outcome = 0;
	NamedPartyTeam team;
};

#endif