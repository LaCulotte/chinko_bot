#ifndef DOFUS_CLIENTCONNECTION_H
#define DOFUS_CLIENTCONNECTION_H

#include "PrefixNetworkConnection.h"
#include "ClientConnection.h"
#include "DofusMessageTypeHandler.h"

class DofusClientConnection : public PrefixNetworkConnection, public ClientConnection {
public: 
    // Constructor
    DofusClientConnection();
    // Copy constructor
    DofusClientConnection(const DofusClientConnection& other) = default;

    // Copy operator
    DofusClientConnection& operator=(const DofusClientConnection& other) = default;
    // Destructor
    virtual ~DofusClientConnection() = default; 

    // Receive a message through connection
    virtual sp<ConnectionMessage> readMessage() override;
    // Send a message through connection
    virtual bool sendMessage(sp<ConnectionMessage> message) override;

    virtual void initHandler() override;

protected:
public:
    // Reads and return necessary prefix data to know the type and the length of the message
    virtual sp<MessageDataBuffer> readPrefix() override;
    // Returns the right message type with only the prefixed data
    virtual sp<PrefixedMessage> deserializePrefix(sp<MessageDataBuffer> prefixData) override;
    // Write the prefix of the message at the beggining of data
    virtual bool serializePrefix(sp<MessageDataBuffer> data, sp<PrefixedMessage> msg) override;

    // Instance id; used in the prefix of the sent messages
    int instance_id = 0;    
};

#endif