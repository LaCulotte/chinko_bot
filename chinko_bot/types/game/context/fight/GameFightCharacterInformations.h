#ifndef GAMEFIGHTCHARACTERINFORMATIONS_H
#define GAMEFIGHTCHARACTERINFORMATIONS_H

#include "GameFightFighterNamedInformations.h"

#include "ActorAlignmentInformations.h"

class GameFightCharacterInformations : public GameFightFighterNamedInformations {
public:
	// Constructor
	GameFightCharacterInformations() {};
	// Copy constructor
	GameFightCharacterInformations(const GameFightCharacterInformations& other) = default;

	// Copy operator
	GameFightCharacterInformations& operator=(const GameFightCharacterInformations& other) = default;
	// Destructor
	~GameFightCharacterInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 5123;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	bool sex = false;
	int breed = 0;
	ActorAlignmentInformations alignmentInfos;
	int level = 0;
};

#endif