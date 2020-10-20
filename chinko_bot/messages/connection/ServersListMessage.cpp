#include "ServersListMessage.h"

bool ServersListMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeShort(servers.size());
	for(int i = 0; i < servers.size(); i++) {
		servers[i].serialize(output);
	}
	output->writeVarShort(alreadyConnectedToServerId);
	output->writeBool(canCreateNewCharacter);

    return true;
}

bool ServersListMessage::deserialize(sp<MessageDataBuffer> input) {
	int servers_size = input->readShort();
	for(int i = 0; i < servers_size; i++) {
		GameServerInformations server;

		if(!server.deserialize(input))
			return false;
		servers.push_back(server);
	}
	alreadyConnectedToServerId = input->readVarShort();
	canCreateNewCharacter = input->readBool();

    return true;
}
