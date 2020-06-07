#ifndef RAWDATA_MESSAGE_H
#define RAWDATA_MESSAGE_H

#include "NetworkMessage.h"

class RawDataMessage : public NetworkMessage {
public:
    // Default constructor.
    RawDataMessage() {};
    // Constructor. Copy dat to message's data buffer.
    RawDataMessage(MessageDataBuffer dat) { data = dat; };
    // Copy contructor
    RawDataMessage(const RawDataMessage& other) = default;

    // Copy operator
    virtual RawDataMessage& operator=(const RawDataMessage& other) = default;
    // Destructor
    virtual ~RawDataMessage() = default;

    // Basically copy object's data to the output buffer.
    virtual bool serialize(sp<MessageDataBuffer> output) override;
    // Basically get object's data from the input buffer.
    virtual bool deserialize(sp<MessageDataBuffer> input) override;

    unsigned int getId() override { return protocolId; };

    static const unsigned int protocolId = 602;

protected:
    // Raw data buffer.
    MessageDataBuffer data;
};

#endif