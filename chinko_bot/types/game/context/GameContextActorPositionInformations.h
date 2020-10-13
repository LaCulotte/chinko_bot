#ifndef GAMECONTEXTACTORPOSITIONINFORMATIONS_H
#define GAMECONTEXTACTORPOSITIONINFORMATIONS_H

#include "NetworkType.h"

#include "EntityDispositionInformations.h"

#include "NetworkTypeHandler.h"

class GameContextActorPositionInformations : public NetworkType {
public:
	// Constructor
	GameContextActorPositionInformations() {};
	// Copy constructor
	GameContextActorPositionInformations(const GameContextActorPositionInformations& other) = default;

	// Copy operator
	GameContextActorPositionInformations& operator=(const GameContextActorPositionInformations& other) = default;
	// Destructor
	~GameContextActorPositionInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 2762;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	sp<EntityDispositionInformations> disposition;
	double contextualId = 0;
};

#endif