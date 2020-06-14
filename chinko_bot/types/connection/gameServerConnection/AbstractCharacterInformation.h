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

    // Returns the type's id
    virtual unsigned int getId() { return typeId; };
    // Type's id
    static const unsigned int typeId = 400;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	uint64_t id;

};

#endif