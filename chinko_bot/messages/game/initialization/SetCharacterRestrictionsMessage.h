#ifndef SETCHARACTERRESTRICTIONSMESSAGE_MESSAGE_H
#define SETCHARACTERRESTRICTIONSMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "ActorRestrictionsInformations.h"

class SetCharacterRestrictionsMessage : public PrefixedMessage {
public:
	// Constructor
	SetCharacterRestrictionsMessage() {};
	// Copy constructor
	SetCharacterRestrictionsMessage(const SetCharacterRestrictionsMessage& other) = default;

	// Copy operator
	SetCharacterRestrictionsMessage& operator=(const SetCharacterRestrictionsMessage& other) = default;
	// Destructor
	~SetCharacterRestrictionsMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 7393;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	ActorRestrictionsInformations restrictions;
	double actorId = 0;
};

#endif