#ifndef OBJECTEFFECTDICE_H
#define OBJECTEFFECTDICE_H

#include "ObjectEffect.h"

class ObjectEffectDice : public ObjectEffect {
public: 
	// Constructor
	ObjectEffectDice() {};
	// Constructor with actionId initialization
	ObjectEffectDice(int actionId) : ObjectEffect(actionId) {};
	// Copy constructor
	ObjectEffectDice(const ObjectEffectDice& other) = default;

	// Copy operator
	ObjectEffectDice& operator=(const ObjectEffectDice& other) = default;
	// Destructor
	~ObjectEffectDice() = default;

	// Returns the type's id
	virtual unsigned int getId() { return typeId; };
	// Type's id
	static const unsigned int typeId = 73;	
	
	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int diceNum;
	int diceSide;
	int diceConst;

};

#endif