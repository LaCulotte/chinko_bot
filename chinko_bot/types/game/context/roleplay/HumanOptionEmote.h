#ifndef HUMANOPTIONEMOTE_H
#define HUMANOPTIONEMOTE_H

#include "HumanOption.h"


class HumanOptionEmote : public HumanOption {
public:
	// Constructor
	HumanOptionEmote() {};
	// Copy constructor
	HumanOptionEmote(const HumanOptionEmote& other) = default;

	// Copy operator
	HumanOptionEmote& operator=(const HumanOptionEmote& other) = default;
	// Destructor
	~HumanOptionEmote() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 407;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	double emoteStartTime = 0;
	int emoteId = 0;
};

#endif