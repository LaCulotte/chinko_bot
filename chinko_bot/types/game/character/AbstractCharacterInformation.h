#ifndef ABSTRACTCHARACTERINFORMATION_H
#define ABSTRACTCHARACTERINFORMATION_H

#include "NetworkType.h"


class AbstractCharacterInformation : public NetworkType {
public:
	// Constructor
	AbstractCharacterInformation() {};
	// Copy constructor
	AbstractCharacterInformation(const AbstractCharacterInformation& other) = default;

	// Copy operator
	AbstractCharacterInformation& operator=(const AbstractCharacterInformation& other) = default;
	// Destructor
	~AbstractCharacterInformation() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 120;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	uint64_t id = 0;
};

#endif