#include "MonsterInGroupInformations.h"

bool MonsterInGroupInformations::serialize(sp<MessageDataBuffer> output) {
	MonsterInGroupLightInformations::serialize(output);

	look.serialize(output);

    return true;
}

bool MonsterInGroupInformations::deserialize(sp<MessageDataBuffer> input) {
	MonsterInGroupLightInformations::deserialize(input);

	if(!look.deserialize(input))
		return false;

    return true;
}
