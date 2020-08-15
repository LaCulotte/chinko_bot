#include "Frame.h"
#ifdef FINISHED_FRAME_H

#ifndef UPDATINGFRAME_H
#define UPDATINGFRAME_H



// Frame that has updates if it computes a message
class UpdatingFrame : public virtual Frame {
public:
    // Constructor
    UpdatingFrame() {};
    // Copy constructor
    UpdatingFrame(const UpdatingFrame& other) = default;
    
    // Copy operator
    virtual UpdatingFrame& operator=(const UpdatingFrame &other) = default;
    // Destructor
    virtual ~UpdatingFrame() = default;

    // Update function
    virtual bool update() = 0;

protected:
    // True if the frame should update at each parent's tick
    bool alwaysUpdate = false;
};

#endif

#endif