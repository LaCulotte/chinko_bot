#ifndef CHARACTERSELECTED_MESSAGE_H
#define CHARACTERSELECTED_MESSAGE_H

#include "PrefixedMessage.h"

// Messages for the selected character's id 
class CharacterSelectedMessage : public PrefixedMessage {
public : 
    // Constructor
    CharacterSelectedMessage() {};
    // Constructor with character's id initialization
    CharacterSelectedMessage(uint64_t id) { this->id = id; }
    // Copy constructor
    CharacterSelectedMessage(const CharacterSelectedMessage& other) = default;

    // Copy operator
    CharacterSelectedMessage& operator=(const CharacterSelectedMessage& other) = default;
    // Destructor
    ~CharacterSelectedMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; };
    // Message's protocol Id
    static const unsigned int protocolId = 11021;

    // Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override { id = input->readInt64(); return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override { output->writeInt64(id); return true; };

    // Selected character's id
    uint64_t id;
};

#endif