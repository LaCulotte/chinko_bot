#include "SelectedServerDataExtendedMessage.h"

bool SelectedServerDataExtendedMessage::serialize(sp<MessageDataBuffer> output) {
	SelectedServerDataMessage::serialize(output);

	output->writeShort(servers.size());
	for(int i = 0; i < servers.size(); i++) {
		servers[i].serialize(output);
	}

    return true;
}

bool SelectedServerDataExtendedMessage::deserialize(sp<MessageDataBuffer> input) {
	SelectedServerDataMessage::deserialize(input);

	int servers_size = input->readShort();
	for(int i = 0; i < servers_size; i++) {
		GameServerInformations server;

		if(!server.deserialize(input))
			return false;
		servers.push_back(server);
	}

    return true;
}
