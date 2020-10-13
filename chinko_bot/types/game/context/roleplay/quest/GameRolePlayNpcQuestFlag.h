#ifndef GAMEROLEPLAYNPCQUESTFLAG_H
#define GAMEROLEPLAYNPCQUESTFLAG_H

#include "NetworkType.h"


class GameRolePlayNpcQuestFlag : public NetworkType {
public:
	// Constructor
	GameRolePlayNpcQuestFlag() {};
	// Copy constructor
	GameRolePlayNpcQuestFlag(const GameRolePlayNpcQuestFlag& other) = default;

	// Copy operator
	GameRolePlayNpcQuestFlag& operator=(const GameRolePlayNpcQuestFlag& other) = default;
	// Destructor
	~GameRolePlayNpcQuestFlag() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 6477;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<int> questsToStartId;
	vector<int> questsToValidId;
};

#endif