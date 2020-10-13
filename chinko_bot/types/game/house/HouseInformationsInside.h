#ifndef HOUSEINFORMATIONSINSIDE_H
#define HOUSEINFORMATIONSINSIDE_H

#include "HouseInformations.h"

#include "HouseInstanceInformations.h"

#include "NetworkTypeHandler.h"

class HouseInformationsInside : public HouseInformations {
public:
	// Constructor
	HouseInformationsInside() {};
	// Copy constructor
	HouseInformationsInside(const HouseInformationsInside& other) = default;

	// Copy operator
	HouseInformationsInside& operator=(const HouseInformationsInside& other) = default;
	// Destructor
	~HouseInformationsInside() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 3148;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int worldY = 0;
	int worldX = 0;
	sp<HouseInstanceInformations> houseInfos;
};

#endif