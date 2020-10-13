#ifndef GAMEROLEPLAYPRISMINFORMATIONS_H
#define GAMEROLEPLAYPRISMINFORMATIONS_H

#include "GameRolePlayActorInformations.h"

#include "PrismInformation.h"

#include "NetworkTypeHandler.h"

class GameRolePlayPrismInformations : public GameRolePlayActorInformations {
public:
	// Constructor
	GameRolePlayPrismInformations() {};
	// Copy constructor
	GameRolePlayPrismInformations(const GameRolePlayPrismInformations& other) = default;

	// Copy operator
	GameRolePlayPrismInformations& operator=(const GameRolePlayPrismInformations& other) = default;
	// Destructor
	~GameRolePlayPrismInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 1573;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	sp<PrismInformation> prism;
};

#endif