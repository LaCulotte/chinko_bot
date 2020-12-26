#include "APIConnection.h"

APIConnection::APIConnection() : PrefixNetworkConnection() {
    this->initHandler();
}

void APIConnection::initHandler() {
    // Construction of the message handler for the API
    this->messageTypeHandler = make_shared<APIMessageTypeHandler>();
}

sp<MessageDataBuffer> APIConnection::readPrefix() {
    // Reads data for a short and an int
    return readData(6);
}

sp<PrefixedMessage> APIConnection::deserializePrefix(sp<MessageDataBuffer> prefixData) {
    // Gets the Id and length of the message
    int id = prefixData->readShort();
    int length = prefixData->readInt();

    // Contruction of the API message
    sp<PrefixedMessage> retMessage = dynamic_pointer_cast<PrefixedMessage>(this->messageTypeHandler->generateMessageById(id));
    
    if(!retMessage)
        return nullptr;

    retMessage->setLength(length);
    return retMessage;
}

bool APIConnection::serializePrefix(sp<MessageDataBuffer> data, sp<PrefixedMessage> message) {
    // Checks of the arguments are valid
    if(!data || !message){
        Logger::write("Error : Tried to serialize a prefix with no data or message!", LOG_IMPORTANT_WARNING);
        Logger::write("File : " + (string) __FILE__ + "; Line : " + to_string(__LINE__), LOG_IMPORTANT_WARNING);

        return false;
    }

    // Gets length of the message's data
    int length = data->size();

    // Inserts the prefix into the sending data
    data->cursor_reset();
    data->insertDataSpace(6);
    data->writeShort(message->getId());
    data->writeInt(length);

    return true;
}

// A NE PAS FAIRE : APIListeningServer appelle onConnection pour récup l'adresse et envoyer un message de refus. NE PAS ENVOYER DE MESSAGE DE CONNECTION ICI.
// void APIConnection::onConnection() {
//     // this->sendMessage(make_shared<APIHelloMessage>());
// }