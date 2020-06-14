#ifndef CHARACTERMINIMALPLUSLOOKINFORMATIONS_H
#define CHARACTERMINIMALPLUSLOOKINFORMATIONS_H

#include "CharacterMinimalInformations.h"
#include "EntityLook.h"

class CharacterMinimalPlusLookInformations : public CharacterMinimalInformations {
public: 
	// Constructor
	CharacterMinimalPlusLookInformations() {};
	// Copy constructor
	CharacterMinimalPlusLookInformations(const CharacterMinimalPlusLookInformations& other) = default;

	// Copy operator
	CharacterMinimalPlusLookInformations& operator=(const CharacterMinimalPlusLookInformations& other) = default;
	// Destructor
	~CharacterMinimalPlusLookInformations() = default;

    // Returns the type's id
    virtual unsigned int getId() { return typeId; };
    // Type's id
    static const unsigned int typeId = 163;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	EntityLook entityLook;
	int breed;

};

#endif