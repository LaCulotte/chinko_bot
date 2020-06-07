#ifndef GETCONNECTIONFOCUS_REQUEST_MESSAGE
#define GETCONNECTIONFOCUS_REQUEST_MESSAGE

#include "Message.h"
#include "Connection.h"
#include <functional>

// Asks for the focus of one or multiple connections.
// In other words, it asks some connections to send the incoming messages to the sending MessagingUnit
class GetConnectionFocusRequestMessage : public Message {
public:
    // Contructor
    GetConnectionFocusRequestMessage() {};
    // Constructor; will get the focus from the connections whose id is 'connectionIds'
    GetConnectionFocusRequestMessage(vector<int> connectionIds) { this->connectionIds = connectionIds; };
    // Constructor; get focus of all the connections that make 'filter' return true
    GetConnectionFocusRequestMessage(function<bool(sp<Connection>)> filter) { this->filter = filter; };
    // Copy constuctor
    GetConnectionFocusRequestMessage(const GetConnectionFocusRequestMessage& other) = default;

    // Copy operator
    virtual GetConnectionFocusRequestMessage& operator=(const GetConnectionFocusRequestMessage& other) = default;
    // Destructor
    virtual ~GetConnectionFocusRequestMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; };
    // Message's protocol Id
    static const unsigned int protocolId = 618;

    /** Ids of the connections to get the focus from
     *  The preferred connection of the source will be the last id in 'connectionIds'
     */
    vector<int> connectionIds = {};
    /** Filter : get the focus of the connections that make 'filter' return true when passed as argument
     *  Will use the filter if connectionIds is empty
     */
    function<bool(sp<Connection>)> filter;

    // True if all the connections passing the filter should change focus
    bool all = false;
    // If 'all = false', the number of connections that shoulld change focus
    int n = 1;
};

#endif