#ifndef CHARACTEREXPERIENCEGAINMESSAGE_MESSAGE_H
#define CHARACTEREXPERIENCEGAINMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class CharacterExperienceGainMessage : public PrefixedMessage {
public:
	// Constructor
	CharacterExperienceGainMessage() {};
	// Copy constructor
	CharacterExperienceGainMessage(const CharacterExperienceGainMessage& other) = default;

	// Copy operator
	CharacterExperienceGainMessage& operator=(const CharacterExperienceGainMessage& other) = default;
	// Destructor
	~CharacterExperienceGainMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 9931;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	uint64_t experienceGuild = 0;
	uint64_t experienceIncarnation = 0;
	uint64_t experienceMount = 0;
	uint64_t experienceCharacter = 0;
};

#endif