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

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 2181;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int breed = 0;
	EntityLook entityLook;
};

#endif