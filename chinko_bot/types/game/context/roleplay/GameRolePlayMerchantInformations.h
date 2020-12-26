#ifndef GAMEROLEPLAYMERCHANTINFORMATIONS_H
#define GAMEROLEPLAYMERCHANTINFORMATIONS_H

#include "GameRolePlayNamedActorInformations.h"

#include "HumanOption.h"

#include "NetworkTypeHandler.h"

class GameRolePlayMerchantInformations : public GameRolePlayNamedActorInformations {
public:
	// Constructor
	GameRolePlayMerchantInformations() {};
	// Copy constructor
	GameRolePlayMerchantInformations(const GameRolePlayMerchantInformations& other) = default;

	// Copy operator
	GameRolePlayMerchantInformations& operator=(const GameRolePlayMerchantInformations& other) = default;
	// Destructor
	~GameRolePlayMerchantInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 9317;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<sp<HumanOption>> options;
	int sellType = 0;
};

#endif