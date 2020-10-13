#ifndef HUMANOPTIONORNAMENT_H
#define HUMANOPTIONORNAMENT_H

#include "HumanOption.h"


class HumanOptionOrnament : public HumanOption {
public:
	// Constructor
	HumanOptionOrnament() {};
	// Copy constructor
	HumanOptionOrnament(const HumanOptionOrnament& other) = default;

	// Copy operator
	HumanOptionOrnament& operator=(const HumanOptionOrnament& other) = default;
	// Destructor
	~HumanOptionOrnament() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 5752;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int ladderPosition = 0;
	int leagueId = 0;
	int level = 0;
	int ornamentId = 0;
};

#endif