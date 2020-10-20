#ifndef API_CONNECTION_H
#define API_CONNECTION_H

#include "PrefixNetworkConnection.h"
#include "APIMessageTypeHandler.h"

class APIConnection : public PrefixNetworkConnection {
public:
    APIConnection();

    // Copy constructor
    APIConnection(const APIConnection& other) = default;

    // Copy operator
    APIConnection& operator=(const APIConnection& other) = default;
    // Destructor
    virtual ~APIConnection() = default; 

    // virtual void onConnection() override;

    virtual void initHandler() override;

protected:
    // Reads and return necessary prefix data to know the type and the length of the message
    virtual sp<MessageDataBuffer> readPrefix() override;
    // Returns the right message type with only the prefixed data
    virtual sp<PrefixedMessage> deserializePrefix(sp<MessageDataBuffer> prefixData) override;
    // Write the prefix of the message at the beggining of data
    virtual bool serializePrefix(sp<MessageDataBuffer> data, sp<PrefixedMessage> msg) override;
};

#endif