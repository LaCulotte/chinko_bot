#ifndef BEGINAUTHENTIFICATION_MESSAGE_H
#define BEGINAUTHENTIFICATION_MESSAGE_H

#include "PrefixedMessage.h"

// Message to request the beginning of an authentification
class BeginAuthentificationMessage : public PrefixedMessage {
public : 
    // Constructor
    BeginAuthentificationMessage() {};
    // Constructor with username and password initialization
    BeginAuthentificationMessage(string username, string password, bool autoConnect = true) { this->username = username; this->password = password; this->autoConnect = autoConnect; }
    // Copy constructor
    BeginAuthentificationMessage(const BeginAuthentificationMessage& other) = default;

    // Copy operator
    BeginAuthentificationMessage& operator=(const BeginAuthentificationMessage& other) = default;
    // Destructor
    ~BeginAuthentificationMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; };
    // Message's protocol Id
    static const unsigned int protocolId = 10040;

    // Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

    string username;
    string password;
    bool autoConnect;

    string serverAdress = "52.17.231.202";
    int port = 5555;
};

#endif