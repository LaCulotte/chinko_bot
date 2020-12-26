#ifndef HOUSEINSTANCEINFORMATIONS_H
#define HOUSEINSTANCEINFORMATIONS_H

#include "NetworkType.h"


class HouseInstanceInformations : public NetworkType {
public:
	// Constructor
	HouseInstanceInformations() {};
	// Copy constructor
	HouseInstanceInformations(const HouseInstanceInformations& other) = default;

	// Copy operator
	HouseInstanceInformations& operator=(const HouseInstanceInformations& other) = default;
	// Destructor
	~HouseInstanceInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 1681;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	bool isSaleLocked = false;
	uint64_t price = 0;
	string ownerName;
	bool isLocked = false;
	bool secondHand = false;
	int instanceId = 0;
};

#endif