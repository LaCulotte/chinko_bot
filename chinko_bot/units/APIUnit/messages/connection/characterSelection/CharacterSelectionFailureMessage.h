#ifndef CHARACTERSELECTION_FAILURE_MESSAGE_H
#define CHARACTERSELECTION_FAILURE_MESSAGE_H

#include "PrefixedMessage.h"

class CharacterSelectionFailureMessage : public PrefixedMessage {
public : 
    // Constructor
    CharacterSelectionFailureMessage() {};
    // Copy constructor
    CharacterSelectionFailureMessage(const CharacterSelectionFailureMessage& other) = default;

    // Copy operator
    CharacterSelectionFailureMessage& operator=(const CharacterSelectionFailureMessage& other) = default;
    // Destructor
    ~CharacterSelectionFailureMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; };
    // Message's protocol Id
    static const unsigned int protocolId = 11023;

    // Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override { return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override { return true; };
};

#endif