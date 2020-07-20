#ifndef GAMEROLEPLAYCHARACTERINFORMATIONS_H
#define GAMEROLEPLAYCHARACTERINFORMATIONS_H

#include "GameRolePlayHumanoidInformations.h"

#include "ActorAlignmentInformations.h"

class GameRolePlayCharacterInformations : public GameRolePlayHumanoidInformations {
public:
	// Constructor
	GameRolePlayCharacterInformations() {};
	// Copy constructor
	GameRolePlayCharacterInformations(const GameRolePlayCharacterInformations& other) = default;

	// Copy operator
	GameRolePlayCharacterInformations& operator=(const GameRolePlayCharacterInformations& other) = default;
	// Destructor
	~GameRolePlayCharacterInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 36;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	ActorAlignmentInformations alignmentInfos;
};

#endif