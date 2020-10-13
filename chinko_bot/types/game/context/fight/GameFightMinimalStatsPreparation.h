#ifndef GAMEFIGHTMINIMALSTATSPREPARATION_H
#define GAMEFIGHTMINIMALSTATSPREPARATION_H

#include "GameFightMinimalStats.h"


class GameFightMinimalStatsPreparation : public GameFightMinimalStats {
public:
	// Constructor
	GameFightMinimalStatsPreparation() {};
	// Copy constructor
	GameFightMinimalStatsPreparation(const GameFightMinimalStatsPreparation& other) = default;

	// Copy operator
	GameFightMinimalStatsPreparation& operator=(const GameFightMinimalStatsPreparation& other) = default;
	// Destructor
	~GameFightMinimalStatsPreparation() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 5419;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int initiative = 0;
};

#endif