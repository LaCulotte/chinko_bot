#ifndef HOUSEONMAPINFORMATIONS_H
#define HOUSEONMAPINFORMATIONS_H

#include "HouseInformations.h"

#include "HouseInstanceInformations.h"

class HouseOnMapInformations : public HouseInformations {
public:
	// Constructor
	HouseOnMapInformations() {};
	// Copy constructor
	HouseOnMapInformations(const HouseOnMapInformations& other) = default;

	// Copy operator
	HouseOnMapInformations& operator=(const HouseOnMapInformations& other) = default;
	// Destructor
	~HouseOnMapInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 510;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<HouseInstanceInformations> houseInstances;
	vector<int> doorsOnMap;
};

#endif