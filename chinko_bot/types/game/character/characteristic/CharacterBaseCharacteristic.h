#ifndef CHARACTERBASECHARACTERISTIC_H
#define CHARACTERBASECHARACTERISTIC_H

#include "NetworkType.h"


class CharacterBaseCharacteristic : public NetworkType {
public:
	// Constructor
	CharacterBaseCharacteristic() {};
	// Copy constructor
	CharacterBaseCharacteristic(const CharacterBaseCharacteristic& other) = default;

	// Copy operator
	CharacterBaseCharacteristic& operator=(const CharacterBaseCharacteristic& other) = default;
	// Destructor
	~CharacterBaseCharacteristic() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 5795;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int contextModif = 0;
	int alignGiftBonus = 0;
	int objectsAndMountBonus = 0;
	int additionnal = 0;
	int base = 0;
};

#endif