#ifndef GAMEROLEPLAYPORTALINFORMATIONS_H
#define GAMEROLEPLAYPORTALINFORMATIONS_H

#include "GameRolePlayActorInformations.h"

#include "PortalInformation.h"

#include "NetworkTypeHandler.h"

class GameRolePlayPortalInformations : public GameRolePlayActorInformations {
public:
	// Constructor
	GameRolePlayPortalInformations() {};
	// Copy constructor
	GameRolePlayPortalInformations(const GameRolePlayPortalInformations& other) = default;

	// Copy operator
	GameRolePlayPortalInformations& operator=(const GameRolePlayPortalInformations& other) = default;
	// Destructor
	~GameRolePlayPortalInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 3053;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	sp<PortalInformation> portal;
};

#endif