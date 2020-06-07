#ifndef MESSAGEDATABUFFER_H
#define MESSAGEDATABUFFER_H

#include "DataBuffer.h"
#include "Logger.h"

class MessageDataBuffer : public DataBuffer<char> {
public:

    // Constructor
    MessageDataBuffer() {};
    // Constructor with char vector initialisation
    MessageDataBuffer(vector<char> dat) : DataBuffer<char>(dat) {};
    // Constructor with char array initialisation
    MessageDataBuffer(char *dat, int size) : DataBuffer<char>(dat, size) {};
    // Copy constructor
    MessageDataBuffer(const MessageDataBuffer& other) : DataBuffer<char>(other) {};

    // Copy operator
    MessageDataBuffer& operator=(const MessageDataBuffer& other) = default;
    // Destructor
    ~MessageDataBuffer() = default;

    // Transforms the data vector into a char array
    char * toCharArray();

    // Read functions for basic data types

    bool readBool();
    char readByte();
    int16_t readShort();
    int16_t readVarShort();
    int readInt();
    int readVarInt();
    string readUTF();
    string readUTFBytes(int length);

    // Write functions for basic data types

    void writeBool(bool b);
    void writeByte(char byte);
    void writeShort(int16_t s);
    void writeVarShort(int16_t s);
    void writeInt(int i);
    void writeVarInt(int i);
    void writeUTF(string UTF);
    void writeUTFBytes(string UTF);

    // Transforms the data buffer into a string
    virtual string toString() override;
};

#endif