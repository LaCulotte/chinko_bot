#ifndef GAMEFIGHTTAXCOLLECTORINFORMATIONS_H
#define GAMEFIGHTTAXCOLLECTORINFORMATIONS_H

#include "GameFightAIInformations.h"


class GameFightTaxCollectorInformations : public GameFightAIInformations {
public:
	// Constructor
	GameFightTaxCollectorInformations() {};
	// Copy constructor
	GameFightTaxCollectorInformations(const GameFightTaxCollectorInformations& other) = default;

	// Copy operator
	GameFightTaxCollectorInformations& operator=(const GameFightTaxCollectorInformations& other) = default;
	// Destructor
	~GameFightTaxCollectorInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 6975;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int level = 0;
	int lastNameId = 0;
	int firstNameId = 0;
};

#endif