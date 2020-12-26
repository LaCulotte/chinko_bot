#ifndef GAMESERVERINFORMATIONS_H
#define GAMESERVERINFORMATIONS_H

#include "NetworkType.h"


class GameServerInformations : public NetworkType {
public:
	// Constructor
	GameServerInformations() {};
	// Copy constructor
	GameServerInformations(const GameServerInformations& other) = default;

	// Copy operator
	GameServerInformations& operator=(const GameServerInformations& other) = default;
	// Destructor
	~GameServerInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 3198;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	double date = 0;
	int charactersSlots = 0;
	int charactersCount = 0;
	int completion = 0;
	int status = 1;
	bool isMonoAccount = false;
	int type = -1;
	bool isSelectable = false;
	int id = 0;
};

#endif