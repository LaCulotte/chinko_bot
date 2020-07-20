#include "ObjectEffectMount.h"

bool ObjectEffectMount::serialize(sp<MessageDataBuffer> output) {
	ObjectEffect::serialize(output);

	int flags0 = (isFeconded<<2) | (sex<<0) | (isFecondationReady<<3) | (isRideable<<1);
	output->writeByte(flags0);

	output->writeVarInt64(id);
	output->writeVarInt64(expirationDate);
	output->writeVarInt(model);
	output->writeUTF(name);
	output->writeUTF(owner);
	output->writeByte(level);
	output->writeVarInt(reproductionCount);
	output->writeVarInt(reproductionCountMax);
	output->writeShort(effects.size());
	for(int i = 0; i < effects.size(); i++) {
		effects[i].serialize(output);
	}
	output->writeShort(capacities.size());
	for(int i = 0; i < capacities.size(); i++) {
		output->writeVarInt(capacities[i]);
	}

    return true;
}

bool ObjectEffectMount::deserialize(sp<MessageDataBuffer> input) {
	ObjectEffect::deserialize(input);

	int flags0 = input->readByte();
	isFeconded = flags0 & (1 << 2);
	sex = flags0 & (1 << 0);
	isFecondationReady = flags0 & (1 << 3);
	isRideable = flags0 & (1 << 1);

	id = input->readVarInt64();
	expirationDate = input->readVarInt64();
	model = input->readVarInt();
	name = input->readUTF();
	owner = input->readUTF();
	level = input->readByte();
	reproductionCount = input->readVarInt();
	reproductionCountMax = input->readVarInt();
	int effects_size = input->readShort();
	for(int i = 0; i < effects_size; i++) {
		ObjectEffectInteger effect;

		if(!effect.deserialize(input))
			return false;
		effects.push_back(effect);
	}
	int capacities_size = input->readShort();
	for(int i = 0; i < capacities_size; i++) {
		int capacitie;

		capacitie = input->readVarInt();
		capacities.push_back(capacitie);
	}

    return true;
}
