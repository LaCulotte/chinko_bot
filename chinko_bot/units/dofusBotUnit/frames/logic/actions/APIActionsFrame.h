#ifndef API_ACTIONS_FRAME_H
#define API_ACTIONS_FRAME_H

#include "DofusBotFrame.h"

#include "CollectInteractivesMessage.h"
#include "CollectInteractiveTypeIdMessage.h"

#include "InteractiveCollectedMessage.h"
#include "NoInteractiveToCollectMessage.h"

#include "TimedMessage.h"

enum APIActionsFrameState {
    aaf_idle,
    aaf_collectingInteractives
};

class APIActionsFrame : public DofusBotFrame {
public: 
    // Constructor
    APIActionsFrame() {};
    // Copy constructor
    APIActionsFrame(const APIActionsFrame& other) = default;

    // Copy operator
    APIActionsFrame& operator=(const APIActionsFrame& other) = default;
    // Destructor
    ~APIActionsFrame() = default;
    
    virtual bool computeMessage(sp<Message> message, int srcId) override;

    // Collects an interactive of the current id
    void collectNextInteractive();
    
protected:
    // Interactives to collect on this map
    vector<int> interactivesTypesIdsToCollect;
    // Index of the current interactive that is being collected
    int currentInteractiveIndex = 0;

    // Frame's state
    APIActionsFrameState currentState = aaf_idle;
};

#endif