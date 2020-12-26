#ifndef BOT_CHARCTERINFORMATIONS_REQUEST_MESSAGE_H
#define BOT_CHARCTERINFORMATIONS_REQUEST_MESSAGE_H

#include "Message.h"

// Requests bot character's informations
class BotCharacterInformationsRequestMessage : public Message {
public:
	// Constructor
	BotCharacterInformationsRequestMessage() {};
	// Copy constructor
	BotCharacterInformationsRequestMessage(const BotCharacterInformationsRequestMessage& other) = default;

	// Copy operator
	BotCharacterInformationsRequestMessage& operator=(const BotCharacterInformationsRequestMessage& other) = default;
	// Destructor
	~BotCharacterInformationsRequestMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10106;
};

#endif