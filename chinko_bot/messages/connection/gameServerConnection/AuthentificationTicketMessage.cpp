#include "AuthentificationTicketMessage.h"

bool AuthentificationTicketMessage::serialize(sp<MessageDataBuffer> output) {
    output->writeUTF(lang);
    output->writeUTF(ticket);

    return true;
}

bool AuthentificationTicketMessage::deserialize(sp<MessageDataBuffer> input) {
    lang = input->readUTF();
    ticket = input->readUTF();

    return true;
}