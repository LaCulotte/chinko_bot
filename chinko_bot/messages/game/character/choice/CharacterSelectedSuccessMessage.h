#ifndef CHARACTERSELECTEDSUCCESSMESSAGE_MESSAGE_H
#define CHARACTERSELECTEDSUCCESSMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "CharacterBaseInformations.h"

class CharacterSelectedSuccessMessage : public PrefixedMessage {
public:
	// Constructor
	CharacterSelectedSuccessMessage() {};
	// Copy constructor
	CharacterSelectedSuccessMessage(const CharacterSelectedSuccessMessage& other) = default;

	// Copy operator
	CharacterSelectedSuccessMessage& operator=(const CharacterSelectedSuccessMessage& other) = default;
	// Destructor
	~CharacterSelectedSuccessMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 8424;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	bool isCollectingStats = false;
	CharacterBaseInformations infos;
};

#endif