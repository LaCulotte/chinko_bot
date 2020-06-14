#include "EntityLook.h"

bool EntityLook::serialize(shared_ptr<MessageDataBuffer> output) {
	output->writeVarShort(bonesId);

	output->writeShort(skins.size());
	for(int skin : skins)
		output->writeVarShort(skin);

	output->writeShort(indexedColors.size());
	for(int indexedColor : indexedColors)
		output->writeInt(indexedColor);
	
	output->writeShort(scales.size());
	for(int scale : scales)
		output->writeVarShort(scale);
	
	output->writeShort(subEntities.size());
	for(EntityLook subEntity : subEntities)
		subEntity.serialize(output);

	return true;
}

bool EntityLook::deserialize(shared_ptr<MessageDataBuffer> input) {
	bonesId = input->readVarShort();

	int skinsLength = input->readShort();
	for(int i = 0; i < skinsLength; i++)
		skins.push_back(input->readVarShort());

	int indexedColorsLength = input->readShort();
	for(int i = 0; i < indexedColorsLength; i++)
		indexedColors.push_back(input->readInt());

	int scalesLength = input->readShort();
	for(int i = 0; i < scalesLength; i++)
		scales.push_back(input->readVarShort());

	int subEntitiesLength = input->readShort();
	for(int i = 0; i < subEntitiesLength; i++) {
		EntityLook subEntity;
		subEntity.deserialize(input);
		subEntities.push_back(subEntity);
	}

	return true;
}
