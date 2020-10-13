#ifndef IDOL_H
#define IDOL_H

#include "NetworkType.h"


class Idol : public NetworkType {
public:
	// Constructor
	Idol() {};
	// Copy constructor
	Idol(const Idol& other) = default;

	// Copy operator
	Idol& operator=(const Idol& other) = default;
	// Destructor
	~Idol() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 2559;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int dropBonusPercent = 0;
	int xpBonusPercent = 0;
	int id = 0;
};

#endif