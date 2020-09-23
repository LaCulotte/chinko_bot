#ifndef CHARACTERMINIMALINFORMATIONS_H
#define CHARACTERMINIMALINFORMATIONS_H

#include "CharacterBasicMinimalInformations.h"


class CharacterMinimalInformations : public CharacterBasicMinimalInformations {
public:
	// Constructor
	CharacterMinimalInformations() {};
	// Copy constructor
	CharacterMinimalInformations(const CharacterMinimalInformations& other) = default;

	// Copy operator
	CharacterMinimalInformations& operator=(const CharacterMinimalInformations& other) = default;
	// Destructor
	~CharacterMinimalInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 8058;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int level = 0;
};

#endif