#include "DofusClientConnection.h"

DofusClientConnection::DofusClientConnection() : PrefixNetworkConnection() {
    initHandler();
}

void DofusClientConnection::initHandler() {
    // Inits the MessageTypeHandler
    messageTypeHandler = make_shared<DofusMessageTypeHandler>();
}

sp<ConnectionMessage> DofusClientConnection::readMessage(){
    sp<ConnectionMessage> ret = PrefixNetworkConnection::readMessage();

    // Increments 'instance_id' every time a message is received
    if(ret)
        instance_id ++;

    return ret;
}

bool DofusClientConnection::sendMessage(sp<ConnectionMessage> message){
    bool ret = PrefixNetworkConnection::sendMessage(message);

    // Increments 'instance_id' every time a message is sent
    if(ret)
        instance_id++;

    return ret;
}

sp<MessageDataBuffer> DofusClientConnection::readPrefix() {
    // Reads first two bytes of the prefix
    sp<MessageDataBuffer> prefixData = readData(2);

    if(!prefixData)
        return nullptr;

    // Gets typeLen
    int typeLen = prefixData->readShort() & 3;

    if(typeLen != 0) {
        // Reads last bytes of the prefix
        sp<MessageDataBuffer> addData = readData(typeLen);

        if(!addData)
            return nullptr;

        // Reads 'typeLen' Bytes
        prefixData->cursor_end();
        prefixData->write(addData->getData());
    }
    // Resets buffer's cursor
    prefixData->cursor_reset();

    return prefixData;
}

sp<PrefixedMessage> DofusClientConnection::deserializePrefix(sp<MessageDataBuffer> prefixData) {

    // Gets prefix data
    int id = prefixData->readShort() >> 2;
    int length = 0;
    while(prefixData->remainingDataSize()){
        length <<= 8;
        length |= prefixData->readByte();
    }

    // Builds corresponding message
    sp<PrefixedMessage> ret_message = dynamic_pointer_cast<PrefixedMessage>(messageTypeHandler->generateMessageById(id));

    if(!ret_message)
        return nullptr;

    // Sets message length
    ret_message->setLength(length);

    return ret_message;
}

bool DofusClientConnection::serializePrefix(sp<MessageDataBuffer> data, sp<PrefixedMessage> message) {
    // Checks if arguments are initialized
    if(!data || !message) {
        Logger::write("Error : Tried to serialize a prefix with no data or message!", LOG_IMPORTANT_WARNING);
        Logger::write("File : " + (string) __FILE__ + "; Line : " + to_string(__LINE__), LOG_IMPORTANT_WARNING);

        return false;
    }

    // Gets usefull data for the prefix 
    int id = message->getId();
    int length = data->size();

    int typeLen = (length > 255) << 1 | (length <= 255 || length > 65535);

    // Prefix's first part
    int prefix = id << 2 | typeLen;

    // Inserts space at the beginning of the data buffer
    data->cursor_reset();
    data->insertDataSpace(2 + 4 + typeLen);
    // Writes the first part of the prefix
    data->writeShort(prefix);
    data->writeInt(instance_id);

    // Writes the last part of the prefix (the message's length)
    while(typeLen > 0) {
        typeLen--;
        data->writeByte((length >> (8 * typeLen)) & 255);
    }

    return true;
}