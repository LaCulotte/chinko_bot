#include "Version.h"

bool Version::serialize(sp<MessageDataBuffer> output) {
	output->writeByte(major);
	output->writeByte(minor);
	output->writeByte(code);
	output->writeInt(build);
	output->writeByte(buildType);

    return true;
}

bool Version::deserialize(sp<MessageDataBuffer> input) {
	major = input->readByte();
	minor = input->readByte();
	code = input->readByte();
	build = input->readInt();
	buildType = input->readByte();

    return true;
}
