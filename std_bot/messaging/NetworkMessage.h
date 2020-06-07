#ifndef FROMCONNECTIONMESSAGE_H
#define FROMCONNECTIONMESSAGE_H

#include "ConnectionMessage.h"

// Message that can be transformed into raw data (char array)
class NetworkMessage : public ConnectionMessage {
public:
    // Turns raw data into the usable data (message's attributes)
    virtual bool deserialize(shared_ptr<MessageDataBuffer> input) = 0;
    // Turns the message's attributes into raw data
    virtual bool serialize(shared_ptr<MessageDataBuffer> output) = 0;
};

#endif