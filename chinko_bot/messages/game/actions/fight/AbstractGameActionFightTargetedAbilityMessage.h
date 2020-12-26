#ifndef ABSTRACTGAMEACTIONFIGHTTARGETEDABILITYMESSAGE_MESSAGE_H
#define ABSTRACTGAMEACTIONFIGHTTARGETEDABILITYMESSAGE_MESSAGE_H

#include "AbstractGameActionMessage.h"


class AbstractGameActionFightTargetedAbilityMessage : public AbstractGameActionMessage {
public:
	// Constructor
	AbstractGameActionFightTargetedAbilityMessage() {};
	// Copy constructor
	AbstractGameActionFightTargetedAbilityMessage(const AbstractGameActionFightTargetedAbilityMessage& other) = default;

	// Copy operator
	AbstractGameActionFightTargetedAbilityMessage& operator=(const AbstractGameActionFightTargetedAbilityMessage& other) = default;
	// Destructor
	~AbstractGameActionFightTargetedAbilityMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 1401;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	bool verboseCast = false;
	bool silentCast = false;
	int critical = 1;
	int destinationCellId = 0;
	double targetId = 0;
};

#endif