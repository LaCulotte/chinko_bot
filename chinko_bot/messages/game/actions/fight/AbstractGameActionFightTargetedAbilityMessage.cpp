#include "AbstractGameActionFightTargetedAbilityMessage.h"

bool AbstractGameActionFightTargetedAbilityMessage::serialize(sp<MessageDataBuffer> output) {
	AbstractGameActionMessage::serialize(output);

	int flags0 = (verboseCast<<1) | (silentCast<<0);
	output->writeByte(flags0);

	output->writeDouble(targetId);
	output->writeShort(destinationCellId);
	output->writeByte(critical);

    return true;
}

bool AbstractGameActionFightTargetedAbilityMessage::deserialize(sp<MessageDataBuffer> input) {
	AbstractGameActionMessage::deserialize(input);

	int flags0 = input->readByte();
	verboseCast = flags0 & (1 << 1);
	silentCast = flags0 & (1 << 0);

	targetId = input->readDouble();
	destinationCellId = input->readShort();
	critical = input->readByte();

    return true;
}
