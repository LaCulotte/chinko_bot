#include "WorkingUnit.h"

sp<thread> WorkingUnit::launch(){
    // Initialize the thread and the run variable
    run = true;
    loopThread = make_shared<thread>(&WorkingUnit::loop, this);

    return loopThread;
}