#ifndef LAUNCHSCRIPT_MESSAGE_H
#define LAUNCHSCRIPT_MESSAGE_H

#include "PrefixedMessage.h"

class LaunchScriptMessage : public PrefixedMessage {
public:
	// Constructor
	LaunchScriptMessage() {};
	// Constructor with scriptPath initialization
	LaunchScriptMessage(string scriptPath) { this->scriptFilePath = scriptPath; };
	// Copy constructor
	LaunchScriptMessage(const LaunchScriptMessage& other) = default;

	// Copy operator
	LaunchScriptMessage& operator=(const LaunchScriptMessage& other) = default;
	// Destructor
	~LaunchScriptMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 11040;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override { scriptFilePath = input->readUTF(); return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override { output->writeUTF(scriptFilePath); return true; };

    string scriptFilePath;
};

#endif