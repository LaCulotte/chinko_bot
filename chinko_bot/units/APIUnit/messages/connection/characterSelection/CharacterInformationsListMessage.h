#ifndef CHARACTERINFORMATIONS_LIST_MESSAGE
#define CHARACTERINFORMATIONS_LIST_MESSAGE

#include "PrefixedMessage.h"
#include "CharacterInformations.h"

// List of characters to select from
class CharacterInformationsListMessage : public PrefixedMessage {
public : 
    // Constructor
    CharacterInformationsListMessage() {};
    // Constructor with character list initialization
    CharacterInformationsListMessage(vector<CharacterInformations> characters) { this->characters = characters; }
    // Copy constructor
    CharacterInformationsListMessage(const CharacterInformationsListMessage& other) = default;

    // Copy operator
    CharacterInformationsListMessage& operator=(const CharacterInformationsListMessage& other) = default;
    // Destructor
    ~CharacterInformationsListMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; };
    // Message's protocol Id
    static const unsigned int protocolId = 11020;

    // Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

    vector<CharacterInformations> characters;
};

#endif