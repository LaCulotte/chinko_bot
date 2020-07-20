#include "HouseOnMapInformations.h"

bool HouseOnMapInformations::serialize(sp<MessageDataBuffer> output) {
	HouseInformations::serialize(output);

	output->writeShort(doorsOnMap.size());
	for(int i = 0; i < doorsOnMap.size(); i++) {
		output->writeInt(doorsOnMap[i]);
	}
	output->writeShort(houseInstances.size());
	for(int i = 0; i < houseInstances.size(); i++) {
		houseInstances[i].serialize(output);
	}

    return true;
}

bool HouseOnMapInformations::deserialize(sp<MessageDataBuffer> input) {
	HouseInformations::deserialize(input);

	int doorsOnMap_size = input->readShort();
	for(int i = 0; i < doorsOnMap_size; i++) {
		int doorsOnMa;

		doorsOnMa = input->readInt();
		doorsOnMap.push_back(doorsOnMa);
	}
	int houseInstances_size = input->readShort();
	for(int i = 0; i < houseInstances_size; i++) {
		HouseInstanceInformations houseInstance;

		if(!houseInstance.deserialize(input))
			return false;
		houseInstances.push_back(houseInstance);
	}

    return true;
}
