#ifndef CHARACTERSELECTION_SUCCESS_MESSAGE_H
#define CHARACTERSELECTION_SUCCESS_MESSAGE_H

#include "PrefixedMessage.h"

// Character selection was successful
class CharacterSelectionSuccessMessage : public PrefixedMessage {
public : 
    // Constructor
    CharacterSelectionSuccessMessage() {};
    // Constructor with character's initialization
    CharacterSelectionSuccessMessage(string name) { this->name = name; }
    // Copy constructor
    CharacterSelectionSuccessMessage(const CharacterSelectionSuccessMessage& other) = default;

    // Copy operator
    CharacterSelectionSuccessMessage& operator=(const CharacterSelectionSuccessMessage& other) = default;
    // Destructor
    ~CharacterSelectionSuccessMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; };
    // Message's protocol Id
    static const unsigned int protocolId = 11022;

    // Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override { name = input->readUTF(); return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override { output->writeUTF(name); return true; };

    // Selected character's name
    string name;
};

#endif