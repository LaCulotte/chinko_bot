#ifndef OBJECTEFFECTDICE_H
#define OBJECTEFFECTDICE_H

#include "ObjectEffect.h"


class ObjectEffectDice : public ObjectEffect {
public:
	// Constructor
	ObjectEffectDice() {};
	// Copy constructor
	ObjectEffectDice(const ObjectEffectDice& other) = default;

	// Copy operator
	ObjectEffectDice& operator=(const ObjectEffectDice& other) = default;
	// Destructor
	~ObjectEffectDice() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 9512;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int diceConst = 0;
	int diceSide = 0;
	int diceNum = 0;
};

#endif