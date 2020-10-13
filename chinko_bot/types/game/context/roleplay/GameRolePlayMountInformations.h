#ifndef GAMEROLEPLAYMOUNTINFORMATIONS_H
#define GAMEROLEPLAYMOUNTINFORMATIONS_H

#include "GameRolePlayNamedActorInformations.h"


class GameRolePlayMountInformations : public GameRolePlayNamedActorInformations {
public:
	// Constructor
	GameRolePlayMountInformations() {};
	// Copy constructor
	GameRolePlayMountInformations(const GameRolePlayMountInformations& other) = default;

	// Copy operator
	GameRolePlayMountInformations& operator=(const GameRolePlayMountInformations& other) = default;
	// Destructor
	~GameRolePlayMountInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 25;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int level = 0;
	string ownerName;
};

#endif