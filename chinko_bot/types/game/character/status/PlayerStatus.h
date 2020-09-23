#ifndef PLAYERSTATUS_H
#define PLAYERSTATUS_H

#include "NetworkType.h"


class PlayerStatus : public NetworkType {
public:
	// Constructor
	PlayerStatus() {};
	// Copy constructor
	PlayerStatus(const PlayerStatus& other) = default;

	// Copy operator
	PlayerStatus& operator=(const PlayerStatus& other) = default;
	// Destructor
	~PlayerStatus() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 6513;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int statusId = 1;
};

#endif