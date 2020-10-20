#include "APIActionsFrame.h"

bool APIActionsFrame::computeMessage(sp<Message> message, int srcId) {
    sp<CollectInteractivesMessage> ciMsg;

    switch (message->getId())
    {
    case CollectInteractivesMessage::protocolId:
        if(currentState == aaf_idle) {
            ciMsg = dynamic_pointer_cast<CollectInteractivesMessage>(message);
            this->interactivesTypesIdsToCollect = ciMsg->interactiveTypeIds;
            currentInteractiveIndex = 0;
            collectNextInteractive();

            currentState = aaf_collectingInteractives;
            if(currentInteractiveIndex < this->interactivesTypesIdsToCollect.size())
                Logger::write("Collecting all interactives of typeId " + to_string(interactivesTypesIdsToCollect[currentInteractiveIndex]), LOG_INFO);
            else 
                Logger::write("No specified interactive id to collect", LOG_WARNING);
        } else {
            Logger::write("Received CollectInteractivesMessage when not supposed to.", LOG_WARNING);
        }
        break;

    case InteractiveCollectedMessage::protocolId:
        if(currentState == aaf_collectingInteractives)
            collectNextInteractive();
        break;
    
    case NoInteractiveToCollectMessage::protocolId:
        if(currentState == aaf_collectingInteractives) {
            currentInteractiveIndex++;
            if(currentInteractiveIndex < interactivesTypesIdsToCollect.size()) {
                collectNextInteractive();
                Logger::write("Collecting all interactives of typeId " + to_string(interactivesTypesIdsToCollect[currentInteractiveIndex]), LOG_INFO);
           } else {
                interactivesTypesIdsToCollect.clear();
                currentInteractiveIndex = 0;
                currentState = aaf_idle;
                Logger::write("All interactives collected.", LOG_INFO);
            }
        }
        break;

    default:
        return false;
    }

    return true;
}

void APIActionsFrame::collectNextInteractive() {
    if(currentInteractiveIndex >= interactivesTypesIdsToCollect.size()) {
        dofusBotParent->sendSelfMessage(make_shared<NoInteractiveToCollectMessage>());
        return;
    }

    int interactiveId = this->interactivesTypesIdsToCollect[currentInteractiveIndex];

    this->dofusBotParent->sendSelfMessage(make_shared<TimedMessage>(make_shared<CollectInteractiveTypeIdMessage>(interactiveId), 500));
}