#include "IdentificationMessage.h"

bool IdentificationMessage::serialize(sp<MessageDataBuffer> output) {
	int flags = (useLoginToken<<2) | (useCertificate<<1) | (autoconnect<<0);
	output->writeByte(flags);

	version.serialize(output);
	output->writeUTF(lang);
	output->writeVarInt(credentials.size());
	for(int i = 0; i < credentials.size(); i++) {
		output->writeByte(credentials[i]);
	}
	output->writeShort(serverId);
	output->writeVarInt64(sessionOptionalSalt);
	output->writeShort(failedAttempts.size());
	for(int i = 0; i < failedAttempts.size(); i++) {
		output->writeVarShort(failedAttempts[i]);
	}

    return true;
}

bool IdentificationMessage::deserialize(sp<MessageDataBuffer> input) {
	int flags = input->readByte();
	useLoginToken = flags & (1 << 2);
	useCertificate = flags & (1 << 1);
	autoconnect = flags & (1 << 0);

	if(!version.deserialize(input))
		return false;
	lang = input->readUTF();
	int credentials_size = input->readVarInt();
	for(int i = 0; i < credentials_size; i++) {
		int credential;

		credential = input->readByte();
		credentials.push_back(credential);
	}
	serverId = input->readShort();
	sessionOptionalSalt = input->readVarInt64();
	int failedAttempts_size = input->readShort();
	for(int i = 0; i < failedAttempts_size; i++) {
		int failedAttempt;

		failedAttempt = input->readVarShort();
		failedAttempts.push_back(failedAttempt);
	}

    return true;
}
