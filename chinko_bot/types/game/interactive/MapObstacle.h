#ifndef MAPOBSTACLE_H
#define MAPOBSTACLE_H

#include "NetworkType.h"


class MapObstacle : public NetworkType {
public:
	// Constructor
	MapObstacle() {};
	// Copy constructor
	MapObstacle(const MapObstacle& other) = default;

	// Copy operator
	MapObstacle& operator=(const MapObstacle& other) = default;
	// Destructor
	~MapObstacle() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 4705;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int state = 0;
	int obstacleCellId = 0;
};

#endif