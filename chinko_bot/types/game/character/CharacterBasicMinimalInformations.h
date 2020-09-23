#ifndef CHARACTERBASICMINIMALINFORMATIONS_H
#define CHARACTERBASICMINIMALINFORMATIONS_H

#include "AbstractCharacterInformation.h"


class CharacterBasicMinimalInformations : public AbstractCharacterInformation {
public:
	// Constructor
	CharacterBasicMinimalInformations() {};
	// Copy constructor
	CharacterBasicMinimalInformations(const CharacterBasicMinimalInformations& other) = default;

	// Copy operator
	CharacterBasicMinimalInformations& operator=(const CharacterBasicMinimalInformations& other) = default;
	// Destructor
	~CharacterBasicMinimalInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 9273;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	string name;
};

#endif