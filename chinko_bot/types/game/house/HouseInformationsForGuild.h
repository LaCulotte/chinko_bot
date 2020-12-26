#ifndef HOUSEINFORMATIONSFORGUILD_H
#define HOUSEINFORMATIONSFORGUILD_H

#include "HouseInformations.h"


class HouseInformationsForGuild : public HouseInformations {
public:
	// Constructor
	HouseInformationsForGuild() {};
	// Copy constructor
	HouseInformationsForGuild(const HouseInformationsForGuild& other) = default;

	// Copy operator
	HouseInformationsForGuild& operator=(const HouseInformationsForGuild& other) = default;
	// Destructor
	~HouseInformationsForGuild() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 8727;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<int> skillListIds;
	int subAreaId = 0;
	int guildshareParams = 0;
	double mapId = 0;
	int worldY = 0;
	int worldX = 0;
	string ownerName;
	bool secondHand = false;
	int instanceId = 0;
};

#endif