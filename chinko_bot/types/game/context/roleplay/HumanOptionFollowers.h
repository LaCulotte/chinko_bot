#ifndef HUMANOPTIONFOLLOWERS_H
#define HUMANOPTIONFOLLOWERS_H

#include "HumanOption.h"

#include "IndexedEntityLook.h"

class HumanOptionFollowers : public HumanOption {
public:
	// Constructor
	HumanOptionFollowers() {};
	// Copy constructor
	HumanOptionFollowers(const HumanOptionFollowers& other) = default;

	// Copy operator
	HumanOptionFollowers& operator=(const HumanOptionFollowers& other) = default;
	// Destructor
	~HumanOptionFollowers() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 2856;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<IndexedEntityLook> followingCharactersLook;
};

#endif