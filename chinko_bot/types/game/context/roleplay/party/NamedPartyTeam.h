#ifndef NAMEDPARTYTEAM_H
#define NAMEDPARTYTEAM_H

#include "NetworkType.h"


class NamedPartyTeam : public NetworkType {
public:
	// Constructor
	NamedPartyTeam() {};
	// Copy constructor
	NamedPartyTeam(const NamedPartyTeam& other) = default;

	// Copy operator
	NamedPartyTeam& operator=(const NamedPartyTeam& other) = default;
	// Destructor
	~NamedPartyTeam() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 9093;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	string partyName;
	int teamId = 2;
};

#endif