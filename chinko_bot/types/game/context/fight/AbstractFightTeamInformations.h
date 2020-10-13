#ifndef ABSTRACTFIGHTTEAMINFORMATIONS_H
#define ABSTRACTFIGHTTEAMINFORMATIONS_H

#include "NetworkType.h"


class AbstractFightTeamInformations : public NetworkType {
public:
	// Constructor
	AbstractFightTeamInformations() {};
	// Copy constructor
	AbstractFightTeamInformations(const AbstractFightTeamInformations& other) = default;

	// Copy operator
	AbstractFightTeamInformations& operator=(const AbstractFightTeamInformations& other) = default;
	// Destructor
	~AbstractFightTeamInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 2465;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int nbWaves = 0;
	int teamSide = 0;
	double leaderId = 0;
	int teamTypeId = 0;
	int teamId = 2;
};

#endif