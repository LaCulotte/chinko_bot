#ifndef WORKINGUNIT_H
#define WORKINGUNIT_H

#include "Logger.h"
#include "thread_include.h"
#include "ptr_include.h"
/**
 * Object that's "working". It has its own thread that loops 'around' tick.
 */ 
class WorkingUnit {
public:
    // Constructor
    WorkingUnit() {};
    // Copy constructor 
    WorkingUnit(const WorkingUnit& other) = default;

    // Copy operator
    virtual WorkingUnit& operator=(const WorkingUnit& other) = default;
    // Destructor
    virtual ~WorkingUnit() = default;

    // Launches the worker and return the working thread
    virtual sp<thread> launch();
    // Stops the worker
    virtual void stop() { run = false; };
    // Waits until the working thread is finished
    virtual void waitThreadEnd() { loopThread->join(); };

protected:
    // Woking thread
    sp<thread> loopThread;

    // True if the loop is running
    bool run = false;

    // Loop
    virtual void loop() { while(run) tick(); };
    // Tick; launched every loop
    virtual void tick() = 0;
};

#endif