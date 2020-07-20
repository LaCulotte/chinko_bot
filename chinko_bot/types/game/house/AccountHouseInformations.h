#ifndef ACCOUNTHOUSEINFORMATIONS_H
#define ACCOUNTHOUSEINFORMATIONS_H

#include "HouseInformations.h"

#include "HouseInstanceInformations.h"

#include "NetworkTypeHandler.h"

class AccountHouseInformations : public HouseInformations {
public:
	// Constructor
	AccountHouseInformations() {};
	// Copy constructor
	AccountHouseInformations(const AccountHouseInformations& other) = default;

	// Copy operator
	AccountHouseInformations& operator=(const AccountHouseInformations& other) = default;
	// Destructor
	~AccountHouseInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 390;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int subAreaId = 0;
	double mapId = 0;
	int worldY = 0;
	int worldX = 0;
	sp<HouseInstanceInformations> houseInfos;
};

#endif