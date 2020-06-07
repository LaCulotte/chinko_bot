#include "MessageDataBuffer.h"

char * MessageDataBuffer::toCharArray(){
    char * ret = (char *) malloc(size() * sizeof(char));

    for(int i = 0; i < size(); i++){
        ret[i] = data[i];
    }

    return ret;
}

bool MessageDataBuffer::readBool(){
    char b = read();

    return !(b == 0);
}

char MessageDataBuffer::readByte(){
    return read();
}

int16_t MessageDataBuffer::readShort(){
    int16_t ret = 0;

    for(char i = 0; i < 2; i++){
        ret <<= 8;
        ret += read();
    }

    return ret;
}

int16_t MessageDataBuffer::readVarShort(){
    int16_t ret = 0;
    char offset = 0;

    for(char i = 0; i < 3; i++){
        char byte = read();

        ret += (byte & 127) << offset;
        offset += 7;

        if(!(byte & 128))
            return ret;
    }

    cerr << "Wrong VarShort Encoding" << endl;
    return ret;
}

int MessageDataBuffer::readInt(){
    int ret = 0;

    for (char i = 0; i < 4; i++){
        ret <<= 8;
        ret += read();
    }

    return ret;
}

int MessageDataBuffer::readVarInt(){
    int ret = 0;
    char offset = 0;

    for(char i = 0; i < 5; i++){
        char byte = read();

        ret += (byte & 127) << offset;
        offset += 7;

        if(!(byte & 128))
            return ret;
    }

    cerr << "Wrong VarInt Encoding" << endl;
    return ret;
}   

string MessageDataBuffer::readUTF(){
    string ret = "";
    int length = readShort();
    
    for(int i = 0; i < length; i++){
        ret += read();
    }

    return ret;
}

string MessageDataBuffer::readUTFBytes(int length){
    string ret = "";

    for(int i = 0; i < length; i++){
        ret += read();
    }

    return ret;
}

void MessageDataBuffer::writeBool(bool b){
    if(b)
        write(1);
    else
        write(0);
}

void MessageDataBuffer::writeByte(char byte){
    write(byte);
}

void MessageDataBuffer::writeShort(int16_t s){
    for(char i = 1; i >= 0; i--){
        write((s >> (8 * i)) & 255);
    }
}

void MessageDataBuffer::writeVarShort(int16_t s){
    while (s > 0){
        char b = s & 127;
        s >>= 7;
        b |= (s > 0) << 7;
        write(b);
    }
}

void MessageDataBuffer::writeInt(int i){
    for(char k = 3; k >= 0; k--){
        write((i >> (8 * k)) & 255);
    }
}

void MessageDataBuffer::writeVarInt(int i){
    while (i > 0){
        char b = i & 127;
        i >>= 7;
        b |= (i > 0) << 7;
        write(b);
    }
}

void MessageDataBuffer::writeUTF(string UTF){
    writeShort(UTF.size());

    for(char c : UTF)
        write(c);
}

void MessageDataBuffer::writeUTFBytes(string UTF){
    for(char c : UTF)
        write(c);
}

string MessageDataBuffer::toString(){
    stringstream str_stream;
    for (char unit : data){
        str_stream << (unsigned int) unit << "; ";
    }
    return str_stream.str();
}