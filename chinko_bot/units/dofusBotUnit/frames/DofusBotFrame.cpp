#include "DofusBotFrame.h"

bool DofusBotFrame::setParent(MessagingUnit* parent) {
    // Tries to set the parent as a DofusBotUnit
    dofusBotParent = dynamic_cast<DofusBotUnit *>(parent);
    if(dofusBotParent) {
        // Saves the parent if successful
        this->parent = parent;
        return true; 
    }

    // If it fails, returns an 'error'
    return false;
}

void DofusBotFrame::killBot(){
    // Do nothing if there is no bot as parent
    if(!dofusBotParent)
        return;

    dofusBotParent->stop();
    // TODO :   Ajouter un moyen de clear completement le bot : Frames, connections, messagingInterfaces, etc...
    //          A faire directement dans les classes WorkingUnit, MessagingUnit & DofusBotUnit (+ comportement pour ConnectionUnit)
}