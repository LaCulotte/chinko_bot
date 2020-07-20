#include "ObjectEffectDice.h"

bool ObjectEffectDice::serialize(sp<MessageDataBuffer> output) {
	ObjectEffect::serialize(output);

	output->writeVarInt(diceNum);
	output->writeVarInt(diceSide);
	output->writeVarInt(diceConst);

    return true;
}

bool ObjectEffectDice::deserialize(sp<MessageDataBuffer> input) {
	ObjectEffect::deserialize(input);

	diceNum = input->readVarInt();
	diceSide = input->readVarInt();
	diceConst = input->readVarInt();

    return true;
}
