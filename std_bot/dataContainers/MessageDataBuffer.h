#ifndef MESSAGEDATABUFFER_H
#define MESSAGEDATABUFFER_H

#include "DataBuffer.h"
#include "Logger.h"

#define uchar unsigned char

class MessageDataBuffer : public DataBuffer<uchar> {
public:

    // Constructor
    MessageDataBuffer() {};
    // Constructor with uchar vector initialisation
    MessageDataBuffer(vector<uchar> dat) : DataBuffer<uchar>(dat) {};
    // Constructor with uchar array initialisation
    MessageDataBuffer(uchar *dat, int size) : DataBuffer<uchar>(dat, size) {};
    // Copy constructor
    MessageDataBuffer(const MessageDataBuffer& other) : DataBuffer<uchar>(other) {};

    // Copy operator
    MessageDataBuffer& operator=(const MessageDataBuffer& other) = default;
    // Destructor
    ~MessageDataBuffer() = default;

    // Transforms the data vector into a uchar array
    uchar * toCharArray();

    // Read functions for basic data types

    bool readBool();
    uchar readByte();
    int16_t readShort();
    int16_t readVarShort();
    int readInt();
    int readVarInt();
    string readUTF();
    string readUTFBytes(int length);

    // Write functions for basic data types

    void writeBool(bool b);
    void writeByte(uchar byte);
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