#ifndef GAMEACTIONMARKEDCELL_H
#define GAMEACTIONMARKEDCELL_H

#include "NetworkType.h"


class GameActionMarkedCell : public NetworkType {
public:
	// Constructor
	GameActionMarkedCell() {};
	// Copy constructor
	GameActionMarkedCell(const GameActionMarkedCell& other) = default;

	// Copy operator
	GameActionMarkedCell& operator=(const GameActionMarkedCell& other) = default;
	// Destructor
	~GameActionMarkedCell() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 2117;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int cellsType = 0;
	int cellColor = 0;
	int zoneSize = 0;
	int cellId = 0;
};

#endif