#ifndef GAMEROLEPLAYTAXCOLLECTORINFORMATIONS_H
#define GAMEROLEPLAYTAXCOLLECTORINFORMATIONS_H

#include "GameRolePlayActorInformations.h"

#include "TaxCollectorStaticInformations.h"

#include "NetworkTypeHandler.h"

class GameRolePlayTaxCollectorInformations : public GameRolePlayActorInformations {
public:
	// Constructor
	GameRolePlayTaxCollectorInformations() {};
	// Copy constructor
	GameRolePlayTaxCollectorInformations(const GameRolePlayTaxCollectorInformations& other) = default;

	// Copy operator
	GameRolePlayTaxCollectorInformations& operator=(const GameRolePlayTaxCollectorInformations& other) = default;
	// Destructor
	~GameRolePlayTaxCollectorInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 148;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int guildLevel = 0;
	int taxCollectorAttack = 0;
	sp<TaxCollectorStaticInformations> identification;
};

#endif