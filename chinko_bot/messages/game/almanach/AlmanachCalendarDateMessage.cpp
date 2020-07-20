#include "AlmanachCalendarDateMessage.h"

bool AlmanachCalendarDateMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeInt(date);

    return true;
}

bool AlmanachCalendarDateMessage::deserialize(sp<MessageDataBuffer> input) {
	date = input->readInt();

    return true;
}
