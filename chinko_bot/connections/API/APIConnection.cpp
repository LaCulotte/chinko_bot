#include "APIConnection.h"

APIConnection::APIConnection() : PrefixNetworkConnection() {
    this->initHandler();
}

void APIConnection::initHandler() {
    this->messageTypeHandler = make_shared<APIMessageTypeHandler>();
}

sp<MessageDataBuffer> APIConnection::readPrefix() {
    // Reads data for a short and an int
    return readData(6);
}

// TODO : implementer APIConnection::serializePrefix() et APIConnection::deserializePrefix()

sp<PrefixedMessage> APIConnection::deserializePrefix(sp<MessageDataBuffer> prefixData) {
    int id = prefixData->readShort();
    int length = prefixData->readInt();

    sp<PrefixedMessage> retMessage = dynamic_pointer_cast<PrefixedMessage>(this->messageTypeHandler->generateMessageById(id));
    
    if(!retMessage)
        return nullptr;

    retMessage->setLength(length);
    return retMessage;
}

bool APIConnection::serializePrefix(sp<MessageDataBuffer> data, sp<PrefixedMessage> message) {
    if(!data || !message){
        Logger::write("Error : Tried to serialize a prefix with no data or message!", LOG_IMPORTANT_WARNING);
        Logger::write("File : " + (string) __FILE__ + "; Line : " + to_string(__LINE__), LOG_IMPORTANT_WARNING);

        return false;
    }

    data->insertDataSpace(6);
    data->writeShort(message->getId());
    data->writeInt(message->getLength());

    return true;
}

// A NE PAS FAIRE : APIListeningServer appelle onConnection pour récup l'adresse et envoyer un message de refus. NE PAS ENVOYER DE MESSAGE DE CONNECTION ICI.
// void APIConnection::onConnection() {
//     // this->sendMessage(make_shared<APIHelloMessage>());
// }