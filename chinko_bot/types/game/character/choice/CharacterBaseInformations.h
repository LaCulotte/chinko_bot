#ifndef CHARACTERBASEINFORMATIONS_H
#define CHARACTERBASEINFORMATIONS_H

#include "CharacterMinimalPlusLookInformations.h"


class CharacterBaseInformations : public CharacterMinimalPlusLookInformations {
public:
	// Constructor
	CharacterBaseInformations() {};
	// Copy constructor
	CharacterBaseInformations(const CharacterBaseInformations& other) = default;

	// Copy operator
	CharacterBaseInformations& operator=(const CharacterBaseInformations& other) = default;
	// Destructor
	~CharacterBaseInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 9272;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	bool sex = false;
};

#endif