#include "ProtocolRequiredMessage.h"

ProtocolRequiredMessage::ProtocolRequiredMessage(int requiredVersion, int currentVersion) {
    this->requiredVersion = requiredVersion;
    this->currentVersion = currentVersion;
}

bool ProtocolRequiredMessage::serialize(sp<MessageDataBuffer> output) {
    output->writeInt(requiredVersion);
    output->writeInt(currentVersion);

    return true;
}

bool ProtocolRequiredMessage::deserialize(sp<MessageDataBuffer> input) {
    requiredVersion = input->readInt();
    currentVersion = input->readInt();

    return true;
}