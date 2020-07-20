#include "AuthenticationTicketMessage.h"

bool AuthenticationTicketMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeUTF(lang);
	output->writeUTF(ticket);

    return true;
}

bool AuthenticationTicketMessage::deserialize(sp<MessageDataBuffer> input) {
	lang = input->readUTF();
	ticket = input->readUTF();

    return true;
}
