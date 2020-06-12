#include "IdentificationMessage.h"

bool IdentificationMessage::serialize(sp<MessageDataBuffer> output) {
    if(credentials.size() == 0) {
        Logger::write("Cannot serialize an IdentificationMessage without credentials", LOG_ERROR);
        return false;
    }

    uchar flags = autoConnect | (useCertificate << 1) | (useToken << 2);
    output->writeByte(flags);    

    output->writeByte(version.major);
    output->writeByte(version.minor);
    output->writeByte(version.code);
    output->writeInt(version.build);
    output->writeByte(version.type);

    output->writeUTF(lang);
    output->writeVarInt(credentials.size());
    output->writeUTFBytes(credentials);

    output->writeShort(serverId);
    output->writeVarInt64(sessionOptionalSalt);

    output->writeShort(failedAttempts.size());
    for(int failedAttempt : failedAttempts){
        output->writeVarShort(failedAttempt);
    }

    return true;
}

bool IdentificationMessage::deserialize(sp<MessageDataBuffer> input) {
    uchar flags = input->readByte();
    autoConnect = flags & 1;
    useCertificate = flags & 2;
    useToken = flags & 4;

    version.major = input->readByte();
    version.minor = input->readByte();
    version.code = input->readByte();
    version.build = input->readInt();
    version.type = input->readByte();

    lang = input->readUTF();

    int credentialsLength = input->readVarInt();
    credentials = input->readUTFBytes(credentialsLength);

    serverId = input->readShort();
    sessionOptionalSalt = input->readVarInt64();

    int failedAttemtpsLength = input->readShort();
    for(int i = 0; i < failedAttemtpsLength; i++) {
        failedAttempts.push_back(input->readVarShort());
    }

    return true;
}