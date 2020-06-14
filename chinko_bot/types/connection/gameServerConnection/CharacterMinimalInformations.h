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

    // Returns the type's id
    virtual unsigned int getId() { return typeId; };
    // Type's id
    static const unsigned int typeId = 110;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int level;

};

#endif