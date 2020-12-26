#ifndef GAMEROLEPLAYNPCINFORMATIONS_H
#define GAMEROLEPLAYNPCINFORMATIONS_H

#include "GameRolePlayActorInformations.h"


class GameRolePlayNpcInformations : public GameRolePlayActorInformations {
public:
	// Constructor
	GameRolePlayNpcInformations() {};
	// Copy constructor
	GameRolePlayNpcInformations(const GameRolePlayNpcInformations& other) = default;

	// Copy operator
	GameRolePlayNpcInformations& operator=(const GameRolePlayNpcInformations& other) = default;
	// Destructor
	~GameRolePlayNpcInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 863;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int specialArtworkId = 0;
	bool sex = false;
	int npcId = 0;
};

#endif