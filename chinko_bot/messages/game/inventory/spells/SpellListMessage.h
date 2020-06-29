#ifndef SPELLLIST_MESSAGE_H
#define SPELLLIST_MESSAGE_H

#include "PrefixedMessage.h"

#include "SpellItem.h"

class SpellListMessage : public PrefixedMessage {
public: 
	// Constructor
	SpellListMessage() {};
	// Copy constructor
	SpellListMessage(const SpellListMessage& other) = default;

	// Copy operator
	SpellListMessage& operator=(const SpellListMessage& other) = default;
	// Destructor
	~SpellListMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 1200;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	bool previsualisation;
	vector<SpellItem> spells;

};

#endif