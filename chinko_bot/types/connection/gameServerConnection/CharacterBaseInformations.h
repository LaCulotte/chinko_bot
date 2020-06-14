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

    // Returns the type's id
    virtual unsigned int getId() { return typeId; };
    // Type's id
    static const unsigned int typeId = 45;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	bool sex;

};

#endif