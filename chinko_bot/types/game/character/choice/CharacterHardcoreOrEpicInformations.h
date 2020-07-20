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

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 474;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int deathMaxLevel = 0;
	int deathCount = 0;
	int deathState = 0;
};

#endif