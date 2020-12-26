#ifndef CASTSPELLONCELL_MESSAGE_H
#define CASTSPELLONCELL_MESSAGE_H

#include "Message.h"

// Requests a spell cast
class CastSpellOnCellMessage : public Message {
public: 
	// Constructor
	CastSpellOnCellMessage() {};
	// Constructor with initialization
	CastSpellOnCellMessage(int cellId, int spellId) { this->cellId = cellId; this->spellId = spellId; };
	// Copy constructor
	CastSpellOnCellMessage(const CastSpellOnCellMessage& other) = default;

	// Copy operator
	CastSpellOnCellMessage& operator=(const CastSpellOnCellMessage& other) = default;
	// Destructor
	~CastSpellOnCellMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10065;

    int cellId = 0;
    int spellId = 0;
};

#endif