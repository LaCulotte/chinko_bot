#include "EntityLook.h"

bool EntityLook::serialize(sp<MessageDataBuffer> output) {
	output->writeVarShort(bonesId);
	output->writeShort(skins.size());
	for(int i = 0; i < skins.size(); i++) {
		output->writeVarShort(skins[i]);
	}
	output->writeShort(indexedColors.size());
	for(int i = 0; i < indexedColors.size(); i++) {
		output->writeInt(indexedColors[i]);
	}
	output->writeShort(scales.size());
	for(int i = 0; i < scales.size(); i++) {
		output->writeVarShort(scales[i]);
	}
	output->writeShort(subentities.size());
	for(int i = 0; i < subentities.size(); i++) {
		subentities[i].serialize(output);
	}

    return true;
}

bool EntityLook::deserialize(sp<MessageDataBuffer> input) {
	bonesId = input->readVarShort();
	int skins_size = input->readShort();
	for(int i = 0; i < skins_size; i++) {
		int skin;

		skin = input->readVarShort();
		skins.push_back(skin);
	}
	int indexedColors_size = input->readShort();
	for(int i = 0; i < indexedColors_size; i++) {
		int indexedColor;

		indexedColor = input->readInt();
		indexedColors.push_back(indexedColor);
	}
	int scales_size = input->readShort();
	for(int i = 0; i < scales_size; i++) {
		int scale;

		scale = input->readVarShort();
		scales.push_back(scale);
	}
	int subentities_size = input->readShort();
	for(int i = 0; i < subentities_size; i++) {
		SubEntity subentitie;

		if(!subentitie.deserialize(input))
			return false;
		subentities.push_back(subentitie);
	}

    return true;
}
