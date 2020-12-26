#ifndef QUERY_SERVERSELECTION_MESSAGE_H
#define QUERY_SERVERSELECTION_MESSAGE_H

#include "Message.h"
#include "GameServerInformations.h"

// Request the server selection from the API client
class QueryServerSelectionMessage : public Message {
public:
	// Constructor
	QueryServerSelectionMessage() {};
	// Constructor with servers list informations
	QueryServerSelectionMessage(vector<GameServerInformations> servers) { this->servers = servers; };
	// Copy constructor
	QueryServerSelectionMessage(const QueryServerSelectionMessage& other) = default;

	// Copy operator
	QueryServerSelectionMessage& operator=(const QueryServerSelectionMessage& other) = default;
	// Destructor
	~QueryServerSelectionMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10102;

	vector<GameServerInformations> servers;
};

#endif