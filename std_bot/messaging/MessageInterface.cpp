#include "MessageInterface.h"
#include "time_include.h"

MessageInterface::MessageInterface(){
}

MessageInterface::MessageInterface(const MessageInterface &other){
    messageBuffer = other.messageBuffer;
}

MessageInterface& MessageInterface::operator=(const MessageInterface &other){
    messageBuffer = other.messageBuffer;

    return *this;
}

MessageInterface::~MessageInterface(){
    messageBuffer.clear();
}

/** Modification warning : If you modify the code of send or receive, you must be
 * careful to not bring deadlocks. If a thread can interrupt either one of these functions
 * and do some other things without releasing the unique_lock, other threads might be blocked 
 * and have to wait around. In certain cases, it could introduce a deadlock!
 * If there is no workaround, you might have to consider implementing a pending messageBuffer, 
 * that can receive messages even if the main messageBuffer is locked. In this case you also have
 * to make sure that the pending buffer cannot be blocked by another thread.
 * Here, we make sure that a thread have to complete the function in order to send or receive
 * messages. 
 */

bool MessageInterface::send(sp<Message> message){
    // Tries to access the messageBuffer
    unique_lock<timed_mutex> mainLock(mainMutex, defer_lock);
    if (mainLock.try_lock_for(chrono::milliseconds(10))){
        // Push the message
        messageBuffer.push_back(message);
        return true;
    }

    // Could not send the message
    Logger::write("Could not write message : MessageInterface is blocked !", LOG_IMPORTANT_WARNING);

    return false;
}

vector<sp<Message>> MessageInterface::receive(){
    if(!isThereMessages())
        return {};

    unique_lock<timed_mutex> mainLock(mainMutex, defer_lock);
    vector<sp<Message>> ret;

    // Tries to access the messages
    if(mainLock.try_lock_for(chrono::milliseconds(100))) {
        // Copies the buffer and clears it
        ret = messageBuffer;
        messageBuffer.clear();
    } else {
        Logger::write("Could not receive messages : MessageInterface is blocked !", LOG_IMPORTANT_WARNING);
    }

    return ret;
}