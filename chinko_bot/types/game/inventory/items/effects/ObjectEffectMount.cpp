#include "ObjectEffectMount.h"

bool ObjectEffectMount::serialize(shared_ptr<MessageDataBuffer> output) {
	if(!ObjectEffect::serialize(output))
		return false;

	int flags = sex | (ridable << 1) | (feconded << 2) | (isFecondationReady << 3);
	output->writeByte(flags);

	output->writeVarInt64(id);
	output->writeVarInt64(expirationDate);
	output->writeVarInt(model);

	output->writeUTF(name);
	output->writeUTF(owner);

	output->writeByte(level);
	output->writeVarInt(reproductionCount);

	output->writeShort(effects.size());
	for(ObjectEffectInteger effect : effects)
		effect.serialize(output);

	output->writeShort(capacities.size());
	for(int capacity : capacities)
		output->writeVarInt(capacity);

	return true;
}

bool ObjectEffectMount::deserialize(shared_ptr<MessageDataBuffer> input) {
	if(!ObjectEffect::deserialize(input))
		return false;

	int flags = input->readByte();
	sex = flags & 1;
	ridable = flags & 2;
	feconded = flags & 4;
	isFecondationReady = flags & 8;

	id = input->readVarInt64();
	expirationDate = input->readVarInt64();
	model = input->readVarInt();

	name = input->readUTF();
	owner = input->readUTF();

	level = input->readByte();
	reproductionCount = input->readVarInt();

	int effectLength = input->readShort();
	for(int i = 0; i < effectLength; i++) {
		ObjectEffectInteger effect;
		effect.deserialize(input);
		effects.push_back(effect);
	}

	int capacitiesLength = input->readShort();
	for(int i = 0; i < capacitiesLength; i++)
		capacities.push_back(input->readVarInt());

	return true;
}
