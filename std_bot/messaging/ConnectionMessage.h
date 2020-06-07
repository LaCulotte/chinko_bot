#ifndef CONNECTION_MESSAGE_H
#define CONNECTION_MESSAGE_H

#include "Message.h"

/** 
 * Message that can hold the connectionId. 
 * Used by a MessagingUnit to make an answer without asking for the connectionId
 */
class ConnectionMessage : public Message {
public :
    // Id if the connection that sent this message
    int sourceConnectionId = -1;
};

#endif