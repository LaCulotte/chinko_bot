#ifndef CHARACTERHARDCOREOREPICINFORMATIONS_H
#define CHARACTERHARDCOREOREPICINFORMATIONS_H

#include "CharacterBaseInformations.h"

class CharacterHardcoreOrEpicInformations : public CharacterBaseInformations {
public: 
	// Constructor
	CharacterHardcoreOrEpicInformations() {};
	// Copy constructor
	CharacterHardcoreOrEpicInformations(const CharacterHardcoreOrEpicInformations& other) = default;

	// Copy operator
	CharacterHardcoreOrEpicInformations& operator=(const CharacterHardcoreOrEpicInformations& other) = default;
	// Destructor
	~CharacterHardcoreOrEpicInformations() = default;

    // Returns the type's id
    virtual unsigned int getId() { return typeId; };
    // Type's id
    static const unsigned int typeId = 474;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int deathState;
	int deathCount;
	int deathMaxLevel;

};

#endif