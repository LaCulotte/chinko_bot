#ifndef HOUSEINFORMATIONS_H
#define HOUSEINFORMATIONS_H

#include "NetworkType.h"


class HouseInformations : public NetworkType {
public:
	// Constructor
	HouseInformations() {};
	// Copy constructor
	HouseInformations(const HouseInformations& other) = default;

	// Copy operator
	HouseInformations& operator=(const HouseInformations& other) = default;
	// Destructor
	~HouseInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 111;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int modelId = 0;
	int houseId = 0;
};

#endif