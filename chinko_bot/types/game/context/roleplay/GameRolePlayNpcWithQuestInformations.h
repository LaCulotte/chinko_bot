#ifndef GAMEROLEPLAYNPCWITHQUESTINFORMATIONS_H
#define GAMEROLEPLAYNPCWITHQUESTINFORMATIONS_H

#include "GameRolePlayNpcInformations.h"

#include "GameRolePlayNpcQuestFlag.h"

class GameRolePlayNpcWithQuestInformations : public GameRolePlayNpcInformations {
public:
	// Constructor
	GameRolePlayNpcWithQuestInformations() {};
	// Copy constructor
	GameRolePlayNpcWithQuestInformations(const GameRolePlayNpcWithQuestInformations& other) = default;

	// Copy operator
	GameRolePlayNpcWithQuestInformations& operator=(const GameRolePlayNpcWithQuestInformations& other) = default;
	// Destructor
	~GameRolePlayNpcWithQuestInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 383;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	GameRolePlayNpcQuestFlag questFlag;
};

#endif