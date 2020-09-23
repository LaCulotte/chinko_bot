#ifndef SPELLLISTMESSAGE_MESSAGE_H
#define SPELLLISTMESSAGE_MESSAGE_H

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
	static const unsigned int protocolId = 3553;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<SpellItem> spells;
	bool spellPrevisualization = false;
};

#endif