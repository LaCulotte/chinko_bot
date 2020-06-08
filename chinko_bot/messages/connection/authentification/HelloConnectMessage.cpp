#include "HelloConnectMessage.h"

HelloConnectMessage::HelloConnectMessage(string salt, char *key, int keyLength){
    this->salt = salt;
    this->key = key;
    this->keyLength = keyLength;
}

bool HelloConnectMessage::serialize(sp<MessageDataBuffer> output) {
    output->writeUTF(salt);
    output->writeVarInt(keyLength);
    // TODO : sécuriser avec un try/catch
    for(int i = 0; i < keyLength; i++){
        output->writeByte(key[i]);
    }

    return true;
}

bool HelloConnectMessage::deserialize(sp<MessageDataBuffer> input) {
    salt = input->readUTF();
    keyLength = input->readVarInt();

    key = (char *) malloc(keyLength * sizeof(char));
    for(int i = 0; i < keyLength; i++){
        key[i] = input->readByte();
    }

    return true;
}