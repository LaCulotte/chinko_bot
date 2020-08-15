#ifndef GAMEFIGHTFIGHTERNAMEDINFORMATIONS_H
#define GAMEFIGHTFIGHTERNAMEDINFORMATIONS_H

#include "GameFightFighterInformations.h"

#include "PlayerStatus.h"

class GameFightFighterNamedInformations : public GameFightFighterInformations {
public:
	// Constructor
	GameFightFighterNamedInformations() {};
	// Copy constructor
	GameFightFighterNamedInformations(const GameFightFighterNamedInformations& other) = default;

	// Copy operator
	GameFightFighterNamedInformations& operator=(const GameFightFighterNamedInformations& other) = default;
	// Destructor
	~GameFightFighterNamedInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 158;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	bool hiddenInPrefight = false;
	int ladderPosition = 0;
	int leagueId = 0;
	PlayerStatus status;
	string name;
};

#endif