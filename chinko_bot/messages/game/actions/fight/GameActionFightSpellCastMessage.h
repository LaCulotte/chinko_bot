#ifndef GAMEACTIONFIGHTSPELLCASTMESSAGE_MESSAGE_H
#define GAMEACTIONFIGHTSPELLCASTMESSAGE_MESSAGE_H

#include "AbstractGameActionFightTargetedAbilityMessage.h"


class GameActionFightSpellCastMessage : public AbstractGameActionFightTargetedAbilityMessage {
public:
	// Constructor
	GameActionFightSpellCastMessage() {};
	// Copy constructor
	GameActionFightSpellCastMessage(const GameActionFightSpellCastMessage& other) = default;

	// Copy operator
	GameActionFightSpellCastMessage& operator=(const GameActionFightSpellCastMessage& other) = default;
	// Destructor
	~GameActionFightSpellCastMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 3754;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<int> portalsIds;
	int spellLevel = 0;
	int spellId = 0;
};

#endif