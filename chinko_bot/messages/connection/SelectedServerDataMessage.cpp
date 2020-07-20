#include "SelectedServerDataMessage.h"

bool SelectedServerDataMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeVarShort(serverId);
	output->writeUTF(address);
	output->writeShort(ports.size());
	for(int i = 0; i < ports.size(); i++) {
		output->writeVarShort(ports[i]);
	}
	output->writeBool(canCreateNewCharacter);
	output->writeVarInt(ticket.size());
	for(int i = 0; i < ticket.size(); i++) {
		output->writeByte(ticket[i]);
	}

    return true;
}

bool SelectedServerDataMessage::deserialize(sp<MessageDataBuffer> input) {
	serverId = input->readVarShort();
	address = input->readUTF();
	int ports_size = input->readShort();
	for(int i = 0; i < ports_size; i++) {
		int port;

		port = input->readVarShort();
		ports.push_back(port);
	}
	canCreateNewCharacter = input->readBool();
	int ticket_size = input->readVarInt();
	for(int i = 0; i < ticket_size; i++) {
		int ticke;

		ticke = input->readByte();
		ticket.push_back(ticke);
	}

    return true;
}
