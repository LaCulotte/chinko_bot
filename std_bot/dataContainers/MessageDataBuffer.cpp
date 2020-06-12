#include "MessageDataBuffer.h"

uchar * MessageDataBuffer::toCharArray(){
    uchar * ret = (uchar *) malloc(size() * sizeof(uchar));

    for(int i = 0; i < size(); i++){
        ret[i] = data[i];
    }

    return ret;
}

bool MessageDataBuffer::readBool(){
    uchar b = read();

    return !(b == 0);
}

uchar MessageDataBuffer::readByte(){
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
        uchar byte = read();

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
        uchar byte = read();

        ret += (byte & 127) << offset;
        offset += 7;

        if(!(byte & 128))
            return ret;
    }

    cerr << "Wrong VarInt Encoding" << endl;
    return ret;
}   

uint64_t MessageDataBuffer::readInt64(){
    uint64_t ret = 0;

    for (char i = 0; i < 8; i++){
        ret <<= 8;
        ret += read();
    }

    return ret;    
}

uint64_t MessageDataBuffer::readVarInt64(){
    uint64_t ret = 0;
    char offset = 0;

    for(char i = 0; i < 9; i++){
        uchar byte = read();

        ret += (byte & 127) << offset;
        offset += 7;

        if(!(byte & 128))
            return ret;
    }

    cerr << "Wrong VarInt64 Encoding" << endl;
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

void MessageDataBuffer::writeByte(uchar byte){
    write(byte);
}

void MessageDataBuffer::writeShort(int16_t s){
    for(char i = 1; i >= 0; i--){
        write((s >> (8 * i)) & 255);
    }
}

void MessageDataBuffer::writeVarShort(int16_t s){
    if(s == 0) {
        write(0);
        return;
    }

    while (s > 0){
        uchar b = s & 127;
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
    if(i == 0) {
        write(0);
        return;
    }

    while (i > 0){
        uchar b = i & 127;
        i >>= 7;
        b |= (i > 0) << 7;
        write(b);
    }
}

void MessageDataBuffer::writeInt64(uint64_t d){
    for(char k = 7; k >= 0; k--){
        write((d >> (8 * k)) & 255);
    }
}

void MessageDataBuffer::writeVarInt64(uint64_t d){
    if(d == 0) {
        write(0);
        return;
    }

    while (d > 0){
        uchar b = d & 127;
        d >>= 7;
        b |= (d > 0) << 7;
        write(b);
    }
}

void MessageDataBuffer::writeUTF(string UTF){
    writeShort(UTF.size());

    for(uchar c : UTF)
        write(c);
}

void MessageDataBuffer::writeUTFBytes(string UTF){
    for(uchar c : UTF)
        write(c);
}

string MessageDataBuffer::toString(){
    stringstream str_stream;
    for (uchar unit : data){
        str_stream << (unsigned int) (unsigned char) unit << ";";
    }
    return str_stream.str();
}