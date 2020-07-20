#ifndef SHORTCUTBARCONTENTMESSAGE_MESSAGE_H
#define SHORTCUTBARCONTENTMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "Shortcut.h"

#include "NetworkTypeHandler.h"

class ShortcutBarContentMessage : public PrefixedMessage {
public:
	// Constructor
	ShortcutBarContentMessage() {};
	// Copy constructor
	ShortcutBarContentMessage(const ShortcutBarContentMessage& other) = default;

	// Copy operator
	ShortcutBarContentMessage& operator=(const ShortcutBarContentMessage& other) = default;
	// Destructor
	~ShortcutBarContentMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 6231;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<sp<Shortcut>> shortcuts;
	int barType = 0;
};

#endif