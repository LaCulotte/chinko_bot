#ifndef FIGHTENTITYDISPOSITIONINFORMATIONS_H
#define FIGHTENTITYDISPOSITIONINFORMATIONS_H

#include "EntityDispositionInformations.h"


class FightEntityDispositionInformations : public EntityDispositionInformations {
public:
	// Constructor
	FightEntityDispositionInformations() {};
	// Copy constructor
	FightEntityDispositionInformations(const FightEntityDispositionInformations& other) = default;

	// Copy operator
	FightEntityDispositionInformations& operator=(const FightEntityDispositionInformations& other) = default;
	// Destructor
	~FightEntityDispositionInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 2127;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	double carryingCharacterId = 0;
};

#endif