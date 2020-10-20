#ifndef QUERY_CHARACTERSELECTION_MESSAGE_H
#define QUERY_CHARACTERSELECTION_MESSAGE_H

#include "Message.h"
#include "CharacterBaseInformations.h"

class QueryCharacterSelectionMessage : public Message {
public:
	// Constructor
	QueryCharacterSelectionMessage() {};
	// Constructor
	QueryCharacterSelectionMessage(vector<sp<CharacterBaseInformations>> characters) { this->characters = characters; };
	// Copy constructor
	QueryCharacterSelectionMessage(const QueryCharacterSelectionMessage& other) = default;

	// Copy operator
	QueryCharacterSelectionMessage& operator=(const QueryCharacterSelectionMessage& other) = default;
	// Destructor
	~QueryCharacterSelectionMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10101;

	vector<sp<CharacterBaseInformations>> characters;
};

#endif