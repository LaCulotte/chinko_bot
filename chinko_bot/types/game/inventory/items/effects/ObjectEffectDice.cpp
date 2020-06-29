#include "ObjectEffectDice.h"

bool ObjectEffectDice::serialize(shared_ptr<MessageDataBuffer> output) {
	if(!ObjectEffect::serialize(output))
		return false;

	output->writeVarInt(diceNum);
	output->writeVarInt(diceSide);
	output->writeVarInt(diceConst);

	return true;
}

bool ObjectEffectDice::deserialize(shared_ptr<MessageDataBuffer> input) {
	if(!ObjectEffect::deserialize(input))
		return false;

	diceNum = input->readVarInt();
	diceSide = input->readVarInt();
	diceConst = input->readVarInt();
	
	return true;
}
