#ifndef GAMEROLEPLAYHUMANOIDINFORMATIONS_H
#define GAMEROLEPLAYHUMANOIDINFORMATIONS_H

#include "GameRolePlayNamedActorInformations.h"

#include "HumanInformations.h"

#include "NetworkTypeHandler.h"

class GameRolePlayHumanoidInformations : public GameRolePlayNamedActorInformations {
public:
	// Constructor
	GameRolePlayHumanoidInformations() {};
	// Copy constructor
	GameRolePlayHumanoidInformations(const GameRolePlayHumanoidInformations& other) = default;

	// Copy operator
	GameRolePlayHumanoidInformations& operator=(const GameRolePlayHumanoidInformations& other) = default;
	// Destructor
	~GameRolePlayHumanoidInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 2640;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int accountId = 0;
	sp<HumanInformations> humanoidInfo;
};

#endif