#include "AlmanachCalendarDateMessage.h"

bool AlmanachCalendarDateMessage::serialize(shared_ptr<MessageDataBuffer> output) {

	output->writeInt(date);

	return true;
}

bool AlmanachCalendarDateMessage::deserialize(shared_ptr<MessageDataBuffer> input) {

	date = input->readInt();

	return true;
}
