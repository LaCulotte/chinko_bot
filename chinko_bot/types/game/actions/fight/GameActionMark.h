#ifndef GAMEACTIONMARK_H
#define GAMEACTIONMARK_H

#include "NetworkType.h"

#include "GameActionMarkedCell.h"

class GameActionMark : public NetworkType {
public:
	// Constructor
	GameActionMark() {};
	// Copy constructor
	GameActionMark(const GameActionMark& other) = default;

	// Copy operator
	GameActionMark& operator=(const GameActionMark& other) = default;
	// Destructor
	~GameActionMark() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 8797;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	bool active = false;
	vector<GameActionMarkedCell> cells;
	int markimpactCell = 0;
	int markSpellLevel = 0;
	int markSpellId = 0;
	int markTeamId = 2;
	int markType = 0;
	int markId = 0;
	double markAuthorId = 0;
};

#endif