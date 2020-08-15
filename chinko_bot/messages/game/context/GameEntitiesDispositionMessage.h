#ifndef GAMEENTITIESDISPOSITIONMESSAGE_MESSAGE_H
#define GAMEENTITIESDISPOSITIONMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "IdentifiedEntityDispositionInformations.h"

class GameEntitiesDispositionMessage : public PrefixedMessage {
public:
	// Constructor
	GameEntitiesDispositionMessage() {};
	// Copy constructor
	GameEntitiesDispositionMessage(const GameEntitiesDispositionMessage& other) = default;

	// Copy operator
	GameEntitiesDispositionMessage& operator=(const GameEntitiesDispositionMessage& other) = default;
	// Destructor
	~GameEntitiesDispositionMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 5696;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<IdentifiedEntityDispositionInformations> dispositions;
};

#endif