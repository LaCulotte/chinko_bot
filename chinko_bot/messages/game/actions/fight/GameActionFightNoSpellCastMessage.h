#ifndef GAMEACTIONFIGHTNOSPELLCASTMESSAGE_MESSAGE_H
#define GAMEACTIONFIGHTNOSPELLCASTMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class GameActionFightNoSpellCastMessage : public PrefixedMessage {
public:
	// Constructor
	GameActionFightNoSpellCastMessage() {};
	// Copy constructor
	GameActionFightNoSpellCastMessage(const GameActionFightNoSpellCastMessage& other) = default;

	// Copy operator
	GameActionFightNoSpellCastMessage& operator=(const GameActionFightNoSpellCastMessage& other) = default;
	// Destructor
	~GameActionFightNoSpellCastMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 7718;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int spellLevelId = 0;
};

#endif