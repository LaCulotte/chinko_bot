#ifndef ATTACKMONSTERGROUP_MESSAGE_H
#define ATTACKMONSTERGROUP_MESSAGE_H

#include "Message.h"

// Message to request the beginning of the GameContext building
class AttackMonsterGroupMessage : public Message {
public: 
	// Constructor
	AttackMonsterGroupMessage() {};
	// Constructor with monsterGroupId initialization
	AttackMonsterGroupMessage(double monsterGroupId) { this->monsterGroupId = monsterGroupId; };
	// Copy constructor
	AttackMonsterGroupMessage(const AttackMonsterGroupMessage& other) = default;

	// Copy operator
	AttackMonsterGroupMessage& operator=(const AttackMonsterGroupMessage& other) = default;
	// Destructor
	~AttackMonsterGroupMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10070;

    double monsterGroupId = 0;
};

#endif