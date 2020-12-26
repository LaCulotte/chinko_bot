#ifndef GAMEFIGHTMONSTERWITHALIGNMENTINFORMATIONS_H
#define GAMEFIGHTMONSTERWITHALIGNMENTINFORMATIONS_H

#include "GameFightMonsterInformations.h"

#include "ActorAlignmentInformations.h"

class GameFightMonsterWithAlignmentInformations : public GameFightMonsterInformations {
public:
	// Constructor
	GameFightMonsterWithAlignmentInformations() {};
	// Copy constructor
	GameFightMonsterWithAlignmentInformations(const GameFightMonsterWithAlignmentInformations& other) = default;

	// Copy operator
	GameFightMonsterWithAlignmentInformations& operator=(const GameFightMonsterWithAlignmentInformations& other) = default;
	// Destructor
	~GameFightMonsterWithAlignmentInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 4758;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	ActorAlignmentInformations alignmentInfos;
};

#endif