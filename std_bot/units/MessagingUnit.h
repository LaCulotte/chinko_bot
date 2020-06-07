#ifndef MESSAGINGUNIT_H
#define MESSAGINGUNIT_H

#include "WorkingUnit.h"
#include "MessageInterface.h"
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <functional>
#include "UpdatingFrame.h"

class Frame;
class UpdatingFrame;
class MessageInterface;

/**
 * WorkingUnit that communicates with other WorkingUnits.
 * The work made by a MessagingUnit is defined throught Frames and triggered throught Messages.
 * Each tick, the MessagingUnit recovers sent messages and then they are processed throught Frames.
 */
class MessagingUnit : public WorkingUnit {
public :
    // Constructor
    MessagingUnit();
    // Copy constructor
    MessagingUnit(const MessagingUnit& other) = default;

    // Copy operator
    virtual MessagingUnit& operator=(const MessagingUnit& other) = default;
    // Destructor
    virtual ~MessagingUnit();

    // Initialize the first frames
    virtual void initFrames();
    // Adds a frame
    bool addFrame(sp<Frame> frame, bool alwaysUpdates = false);

    // Returns a frame that can cast into T
    template<typename T>
    sp<Frame> getFrame();
    // Returns multiple frames that can cast into T
    template<typename T>
    vector<sp<Frame>> getFrames(int n, bool fill = false);
    // Returns all the frames that can cast into T
    template<typename T>
    vector<sp<Frame>> getAllFrames();

    // Remove 'frame'
    sp<Frame> removeFrame(sp<Frame> frame);
    // Remove 'frame'
    sp<Frame> removeFrame(Frame * frame);
    // Remove multiple 'frames'
    vector<sp<Frame>> removeFrames(vector<sp<Frame>> frames, bool with_nullptr = true);
    // Remove multiple 'frames'
    vector<Frame *> removeFrames(vector<Frame *> frames, bool with_nullptr = true);

    // Remove a frame that can cast into T
    template<typename T>
    sp<Frame> popFrame();
    // Remove multiple frames that can cast into T
    template<typename T>
    vector<sp<Frame>> popFrames(int n, bool fill = false);
    // Remove all the frames that can cast into T
    template<typename T>
    vector<sp<Frame>> popAllFrames();

    // Links two MessagingUnits
    static bool link(sp<MessagingUnit> mu1, sp<MessagingUnit> mu2);

    // Sends a message to the MessagingUnit without being a MessagingUnit
    bool sendSelfMessage(sp<Message> message);
    // Sends a message to the messagingUnit of id 'destId' 
    bool sendMessage(sp<Message> message, int destId);

    /** Gets the id of a MessageInterface which destination can cast into T. 
     * This id can differ depending on the messagingUnit you ask
     */
    template<typename T>
    int getMessageInterfaceOutId();
    /** Gets the id of a MessageInterface which destination can cast into T and makes filter return true. 
     * This id can differ depending on the messagingUnit you ask
     */
    template<typename T>
    int getMessageInterfaceOutId(function<bool(sp<T>)> filter);
    /** Gets the id of all the MessageInterface which destination can cast into T. 
     * This id can differ depending on the messagingUnit you ask
     */
    template<typename T>
    vector<int> getAllMessageInterfaceOutIds();
    /** Gets the id of all the MessageInterface which destination can cast into T and makes filter return true. 
     * This id can differ depending on the messagingUnit you ask
     */
    template<typename T>
    vector<int> getAllMessageInterfaceOutIds(function<bool(sp<T>)> filter);

    // Removes the messageInterface of id 'interfaceId'
    virtual bool removeMessageInterface(int interfaceId);
    // Removes the messageInterface at the iterator 'interfaceIt'
    virtual bool removeMessageInterface(map<int, sp<MessageInterface>*>::iterator interfaceIt);

    // Description of the MessagingUnit. Used to find a special messagingInterface with 'getMessageInterfaceOutId''s filter
    string messagingUnitDescription = "BasicMessagingUnit";
protected:

    // Tick; launched every loop
    virtual void tick() override;

    // Frames of the MessagingUnit, ordered by priority
    multimap<int, sp<Frame>> frames;
    // Frames that are already added to the MessagingUnit
    unordered_set<sp<Frame>> addedFrames;
    // Frames that are updated each tick
    vector<sp<UpdatingFrame>> alwaysUptadingFrames;  
    // Removes a Frame from all arrays
    void removeFrameFromArrays(multimap<int, sp<Frame>>::iterator itr);  

    // Messages that will be processed by the frames, with the source MessagingUnit
    vector<pair<int, sp<Message>>> messagesToProcess;

    // Adds a pair of MessageInterfaces
    int addMessageInterfaces(sp<MessageInterface> interface_in, sp<MessageInterface> interface_out);
    // Id of the last added MessageInterface
    int lastMsgInterfacesId = 0;
    // Message interface used by objects that are not linked (one-way communication)
    sp<MessageInterface> msgInterfaceExtern;
    // Map id -> pair of MessageInterfaces ([0] = in, [1] = out)
    map<int, sp<MessageInterface>*> msgInterfaces;

    // Retreive the messages from the incoming MessageInterfaces
    void retreiveMessages();
};

template<typename T>
sp<Frame> MessagingUnit::popFrame(){
    for(multimap<int, sp<Frame>>::iterator it = frames.begin(); it != frames.end(); it++){
        if(dynamic_pointer_cast<T>(it->second)) {
            removeFrameFromArrays(it);
            return it->second;
        }
    }

    return nullptr;
}

template<typename T>
vector<sp<Frame>> MessagingUnit::popFrames(int n, bool fill){
    vector<sp<Frame>> ret;

    for(multimap<int, sp<Frame>>::iterator it = frames.begin(); it != frames.end() && ret.size() < n; it++){
        if(dynamic_pointer_cast<T>(it->second)) {
            ret.push_back(it->second);
            removeFrameFromArrays(it);
            it--;
        }
    }

    if(fill)
        while(ret.size() < n)
            ret.push_back(nullptr);

    return ret;
}

template<typename T>
vector<sp<Frame>> MessagingUnit::popAllFrames(){
    vector<sp<Frame>> ret;

    for(multimap<int, sp<Frame>>::iterator it = frames.begin(); it != frames.end(); it++){
        if(dynamic_pointer_cast<T>(it->second)) {
            // delIterators.push_back(it);
            ret.push_back(it->second);
            removeFrameFromArrays(it);
            it--;
        }
    }

    return ret;
}

template<typename T>
sp<Frame> MessagingUnit::getFrame(){
    for(multimap<int, sp<Frame>>::iterator it = frames.begin(); it != frames.end(); it++) {
        if(dynamic_pointer_cast<T>(it->second))
            return it->second;
    }

    return nullptr;
}

template<typename T>
vector<sp<Frame>> MessagingUnit::getFrames(int n, bool fill){
    vector<sp<Frame>> ret;

    for(multimap<int, sp<Frame>>::iterator it = frames.begin(); it != frames.end() && ret.size() < n; it++) {
        if(dynamic_pointer_cast<T>(it->second))
            ret.push_back(it->second);
    }

    if(fill)
        while(ret.size() < n)
            ret.push_back(nullptr);

    return ret;
}

template<typename T>
vector<sp<Frame>> MessagingUnit::getAllFrames(){
    vector<sp<Frame>> ret;

    for(multimap<int, sp<Frame>>::iterator it = frames.begin(); it != frames.end(); it++) {
        if(dynamic_pointer_cast<T>(it->second))
            ret.push_back(it->second);
    }

    return ret;
}

#ifdef END_MESSAGEINTERFACE_H

template<typename T>
int MessagingUnit::getMessageInterfaceOutId(){
    for(auto it = msgInterfaces.begin(); it != msgInterfaces.end(); it++){
        if(it->second[1] && dynamic_cast<T *>(it->second[1]->destination))
            return it->first;
    }

    return -1;
}

template<typename T>
int MessagingUnit::getMessageInterfaceOutId(function<bool(sp<T>)> filter){
    for(auto it = msgInterfaces.begin(); it != msgInterfaces.end(); it++){
        if(it->second[1]){
            sp<T> T_cast = dynamic_cast<T *>(it->second[1]->destination);
            if(T_cast && filter(T_cast))
                return it->first;
        }
    }

    return -1;
}

template<typename T>
vector<int> MessagingUnit::getAllMessageInterfaceOutIds(){
    vector<int> ret;

    for(auto it = msgInterfaces.begin(); it != msgInterfaces.end(); it++){
        if(it->second[1] && dynamic_cast<T *>(it->second[1]->destination))
            ret.push_back(it->first);
    }

    return ret;
}

template<typename T>
vector<int> MessagingUnit::getAllMessageInterfaceOutIds(function<bool(sp<T>)> filter){
    vector<int> ret;

    for(auto it = msgInterfaces.begin(); it != msgInterfaces.end(); it++){
        if(it->second[1]){
            sp<T> T_cast = dynamic_cast<T *>(it->second[1]->destination);
            if(T_cast && filter(T_cast))
                ret.push_back(it->first);
        }
    }

    return ret;
}

#endif

#endif