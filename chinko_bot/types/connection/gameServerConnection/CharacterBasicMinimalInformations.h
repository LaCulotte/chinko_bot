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

    // Returns the type's id
    virtual unsigned int getId() { return typeId; };
    // Type's id
    static const unsigned int typeId = 503;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	string name;

};

#endif