#include "APIFrame.h"

bool APIFrame::setParent(MessagingUnit* parent) {
    apiUnitParent = dynamic_cast<APIUnit *>(parent);
    if(apiUnitParent) {
        if(Frame::setParent(parent))
            return true;
        else 
            apiUnitParent = nullptr;
    }

    return false;
}