#include "APIActionsFrame.h"

#include "AllInteractivesCollectedMessage.h"

bool APIActionsFrame::computeMessage(sp<Message> message, int srcId) {
    sp<CollectInteractivesMessage> ciMsg;

    switch (message->getId())
    {
    case CollectInteractivesMessage::protocolId:
        // Command to collect interactives on the current map
        if(currentState == aaf_idle) {
            ciMsg = dynamic_pointer_cast<CollectInteractivesMessage>(message);
            // Sets list of interactives to collect
            this->interactivesTypesIdsToCollect = ciMsg->interactiveTypeIds;
            currentInteractiveIndex = 0;
            // Collects first interative
            collectNextInteractive();

            // Sets frame's state
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
            // When an interactive is collected, collects the next 
            collectNextInteractive();
        break;
    
    case NoInteractiveToCollectMessage::protocolId:
        if(currentState == aaf_collectingInteractives) {
            // Indent the interactive type's index
            currentInteractiveIndex++;
            if(currentInteractiveIndex < interactivesTypesIdsToCollect.size()) {
                // Collect next type of interactives
                collectNextInteractive();
                Logger::write("Collecting all interactives of typeId " + to_string(interactivesTypesIdsToCollect[currentInteractiveIndex]), LOG_INFO);
           } else {
                // If there is no more interactives to collect, finishes/resets and notify the bot
                interactivesTypesIdsToCollect.clear();
                currentInteractiveIndex = 0;
                currentState = aaf_idle;

                Logger::write("All interactives collected.", LOG_INFO);
                dofusBotParent->sendSelfMessage(make_shared<AllInteractivesCollectedMessage>());
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
        // Stops the collecting if there is no more interactive to collect
        dofusBotParent->sendSelfMessage(make_shared<NoInteractiveToCollectMessage>());
        return;
    }

    // Gets interactives to collect's id
    int interactiveId = this->interactivesTypesIdsToCollect[currentInteractiveIndex];

    // Send a message to collect one of them
    this->dofusBotParent->sendSelfMessage(make_shared<TimedMessage>(make_shared<CollectInteractiveTypeIdMessage>(interactiveId), 500 + (rand() % 500)));
}