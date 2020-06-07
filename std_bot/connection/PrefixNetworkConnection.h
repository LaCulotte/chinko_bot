#ifndef PREFIXNETWORKCONNECTION_H
#define PREFIXNETWORKCONNECTION_H

#include "NetworkConnection.h"
#include "PrefixedMessage.h"
#include "Logger.h"

// This class is made to work with PrefixedMessages
// The prefix template is common to all the messages handled by this connection
// Additionnaly, this class implements the mechanism of pending messages
// When the content of a PrefixedMessage is send throught multiple packet,
//  not all the data can be read at once. The connection saves the read data and returns no message.
//  On the next time a message is request, it will try to read the rest of the message.
// This mechanism loops until all the content is read or until the rest of the data does not arrives.
// The latter is configured through the "maxTimeBetweenPendingUpdates" variable. 

class PrefixNetworkConnection : public virtual NetworkConnection {
public:
    // Constructor
    PrefixNetworkConnection();
    // Copy constructor
    PrefixNetworkConnection(const PrefixNetworkConnection& other);

    // Copy operator
    virtual PrefixNetworkConnection& operator=(const PrefixNetworkConnection& other);
    // Destructor
    virtual ~PrefixNetworkConnection() = default;

    // Receive a message through connection
    virtual sp<ConnectionMessage> readMessage() override;
    // Receive mutliple messages through connection
    virtual vector<sp<ConnectionMessage>> readMessages(int n, bool fill = true) override;
    // Receive all messages through connection
    virtual vector<sp<ConnectionMessage>> readAllMessages() override;

    // Send a message through connection
    virtual bool sendMessage(sp<ConnectionMessage> message) override;

protected:
    // Reads and return necessary prefix data to know the type and the length of the message
    virtual sp<MessageDataBuffer> readPrefix() = 0;
    // Returns the right message type with only the prefixed data
    virtual sp<PrefixedMessage> deserializePrefix(sp<MessageDataBuffer> prefixData) = 0;
    // Write the prefix of the message at the beggining of data
    virtual bool serializePrefix(sp<MessageDataBuffer> data, sp<PrefixedMessage> msg) = 0;

    /**
     * If the data requested is bigger than the data contained in the socket read buffer, the 
     * connection with save the read data in a 'pending' buffer and free the current thread. 
     * The next time data is requested, the connection will continue from the saved (pending) data,
     * until the length requested is read or until an other message is requested.
     */
    // True if there is a pending message
    bool pending = false;
    // Saved (pending) data
    sp<MessageDataBuffer> pendingData;
    // Requested length of the final data
    int pendingDataFinalLength;
    // Saved and incomplete message
    sp<PrefixedMessage> pendingMessage;
    // Last time where pending data was read
    chrono::system_clock::time_point timeLastPendingUpdate;
    /**
     * Maximum time between two following packets so they can be considered from the same message
     * nullptr means that two packets can be infinitly appart and still can be consedered from the same message
     */
    chrono::system_clock::duration *maxTimeBetweenPendingUpdates;
    // Resets the pending variables
    void resetPending();
};

#endif