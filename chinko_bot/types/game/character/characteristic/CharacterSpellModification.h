#ifndef CHARACTERSPELLMODIFICATION_H
#define CHARACTERSPELLMODIFICATION_H

#include "NetworkType.h"

#include "CharacterBaseCharacteristic.h"

class CharacterSpellModification : public NetworkType {
public:
	// Constructor
	CharacterSpellModification() {};
	// Copy constructor
	CharacterSpellModification(const CharacterSpellModification& other) = default;

	// Copy operator
	CharacterSpellModification& operator=(const CharacterSpellModification& other) = default;
	// Destructor
	~CharacterSpellModification() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 9332;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	CharacterBaseCharacteristic value;
	int spellId = 0;
	int modificationType = 0;
};

#endif