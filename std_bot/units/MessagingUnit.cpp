#include "MessagingUnit.h"

MessagingUnit::MessagingUnit(){
    msgInterfaceExtern = make_shared<MessageInterface>();
    msgInterfaceExtern->destination = this;
}

void MessagingUnit::initFrames() {
}

MessagingUnit::~MessagingUnit(){
    // Resets the parents of all the attached Frames
    for(multimap<int, sp<Frame>>::iterator it = frames.begin(); it != frames.end(); it++)
        if(it->second->getParent() == this)
            it->second->resetParent();

    // Resets the destination of all incoming MessageInterfaces
    for(auto it = msgInterfaces.begin(); it != msgInterfaces.end(); it++){
        it->second[0]->destination = nullptr;
        free(it->second);
    }

    if(msgInterfaceExtern)
        msgInterfaceExtern->destination = nullptr;

}

bool MessagingUnit::addFrame(sp<Frame> frame, bool alwaysUpdates){ 
    // Checks if the frame is valid
    if(!frame || addedFrames.find(frame) != addedFrames.end())
        return false;

    // Tries to to set the Frame's parent
    if(!frame->setParent(this))
        return false;

    // Insert frame in the correct containers
    addedFrames.insert(frame);

    frames.insert(pair<int, sp<Frame>>(frame->getPriority(), frame));

    if(alwaysUpdates){
        sp<UpdatingFrame> upFrame = dynamic_pointer_cast<UpdatingFrame>(frame);
        if(upFrame)
            alwaysUptadingFrames.push_back(upFrame);
    }


    return true;
}

void MessagingUnit::removeFrameFromArrays(multimap<int, sp<Frame>>::iterator itr){
    // Removes frame from the main frames' container
    sp<Frame> frame = itr->second;
    frames.erase(itr);

    // Finds and removes the frame from other containers
    if(frame && dynamic_pointer_cast<UpdatingFrame>(frame)){
        for(int i = 0; i < alwaysUptadingFrames.size(); i++)
            if(alwaysUptadingFrames[i] == frame) {
                alwaysUptadingFrames.erase(alwaysUptadingFrames.begin() + i);
                break;
            }
    }

    auto it = addedFrames.find(frame);
    if(it != addedFrames.end())
        addedFrames.erase(it);
}

sp<Frame> MessagingUnit::removeFrame(sp<Frame> frame) {
    // Finds and remove the frame
    for(multimap<int, sp<Frame>>::iterator it = frames.lower_bound(frame->getPriority()); it != frames.upper_bound(frame->getPriority()); it++){
        if(it->second == frame) {
            removeFrameFromArrays(it);
            return it->second;
        }
    }

    return nullptr;
}

sp<Frame> MessagingUnit::removeFrame(Frame * frame) {
    // Finds and remove the frame
    for(multimap<int, sp<Frame>>::iterator it = frames.lower_bound(frame->getPriority()); it != frames.upper_bound(frame->getPriority()); it++){
        if(it->second.get() == frame) {
            removeFrameFromArrays(it);
            return it->second;
        }
    }

    return nullptr;   
}

vector<sp<Frame>> MessagingUnit::removeFrames(vector<sp<Frame>> frames, bool with_nullptr){
    // Returning vector. Contains the frames that were removed
    vector<sp<Frame>> retFrames;

    // Remove the frames
    for(sp<Frame> frame : frames){
        if(with_nullptr) {
            retFrames.push_back(removeFrame(frame));
        } else {
            sp<Frame> removedFrame = removeFrame(frame);
            if(removedFrame)
                retFrames.push_back(removedFrame);
        }
    }

    return retFrames;
}

vector<Frame *> MessagingUnit::removeFrames(vector<Frame *> frames, bool with_nullptr){
    // Returning vector. Contains the frames that were removed
    vector<Frame *> retFrames;

    // Remove the frames
    for(Frame * frame : frames){
        if(with_nullptr) {
            retFrames.push_back(removeFrame(frame).get());
        } else {
            sp<Frame> removedFrame = removeFrame(frame);
            if(removedFrame)
                retFrames.push_back(removedFrame.get());
        }
    }

    return retFrames;
}

int MessagingUnit::addMessageInterfaces(sp<MessageInterface> interface_in, sp<MessageInterface> interface_out){
    // Checks if the MessageInterfaces are valid
    if(!interface_in || !interface_out)
        return -1;

    // Sets the in interface
    interface_in->destination = this;

    // Adds MessageInterfaces
    sp<MessageInterface> *itPair = (sp<MessageInterface>*) calloc(2, sizeof(sp<MessageInterface>));
    itPair[0] = interface_in;
    itPair[1] = interface_out;
    msgInterfaces.insert(pair<int, sp<MessageInterface>*>(lastMsgInterfacesId++, itPair));

    return lastMsgInterfacesId - 1;
}

bool MessagingUnit::removeMessageInterface(int interfaceId){
    // Find and remove MessageInterface
    auto it = msgInterfaces.find(interfaceId);
    if(it != msgInterfaces.end()) {
        removeMessageInterface(it);

        return true;
    } else {
        return false;
    }
}

bool MessagingUnit::removeMessageInterface(map<int, sp<MessageInterface>*>::iterator interfaceIt){
    if(interfaceIt->second) {
        // Unsets in MessageInterface destination
        interfaceIt->second[0]->destination = nullptr;
        // If the out destination is unset, frees both MessageInterfaces
        if(!interfaceIt->second[1]->destination)
            free(interfaceIt->second);
    }

    // Removes interfaces
    msgInterfaces.erase(interfaceIt);

    return true;
}

bool MessagingUnit::link(sp<MessagingUnit> mu1, sp<MessagingUnit> mu2){
    // Checks if the MessagingUnits are valid
    if(!mu1 || !mu2)
        return false;
    
    // Creates the interfaces
    sp<MessageInterface> in1out2 (new MessageInterface());
    sp<MessageInterface> in2out1 (new MessageInterface());

    // Adds the interfaces
    mu1->addMessageInterfaces(in1out2, in2out1);
    mu2->addMessageInterfaces(in2out1, in1out2);

    return true;
}

bool MessagingUnit::sendSelfMessage(sp<Message> message){
    msgInterfaceExtern->send(message);
    return true;
}

bool MessagingUnit::sendMessage(sp<Message> message, int destId){

    // Find the MessageInterface
    if(msgInterfaces.find(destId) != msgInterfaces.end()){
        sp<MessageInterface> out = msgInterfaces.at(destId)[1];

        if(out && out->destination) {
            // If the interface is valid, send the message
            out->send(message);
            return true;
        } else {
            // If it is invalid, removes it
            removeMessageInterface(destId);
        }  
    }

    return false;
}

void MessagingUnit::retreiveMessages(){

    // Receive messages from all the MessageInterfaces
    for(auto it = msgInterfaces.begin(); it != msgInterfaces.end(); it++) {
        if(it->second[0] && it->second[1] && it->second[1]->destination){
            vector<sp<Message>> messages = it->second[0]->receive();
            for(sp<Message> m : messages)
                messagesToProcess.push_back(pair(it->first, m));

        } else {
            // If the interface is invalid, removes it
            removeMessageInterface(it);
        }
    }

    // Receive messages from all other MessageInterfaces
    if(msgInterfaceExtern)
        for(sp<Message> msg : msgInterfaceExtern->receive())
            messagesToProcess.push_back(pair(-1, msg));

}

void MessagingUnit::tick(){
    // Retreive messages
    retreiveMessages();

    // Frames that will be updated
    unordered_set<sp<UpdatingFrame>> toUpdateFrames;

    // Go through all the messages
    for(int i = 0; i < messagesToProcess.size(); i++){
        sp<Message> message = messagesToProcess[i].second;
        message->keepInLoop = false;
        bool processed = false;

        // Submit it to all the frames until a frame can process it and 'keepInLoop' attribute is false
        for(multimap<int, sp<Frame>>::iterator it = frames.begin(); it != frames.end(); it++) {
            if(it->second->computeMessage(message, messagesToProcess[i].first)) {
                processed = true;

                // If the message has been proccessed and the frame can update, then it will be updated
                if(dynamic_pointer_cast<UpdatingFrame>(it->second))
                    toUpdateFrames.insert(dynamic_pointer_cast<UpdatingFrame>(it->second));

                if(!message->keepInLoop)
                    break;

                message->keepInLoop = false;
            }
        }            

        // Removes the message if it has been processed or if it has not lifetime yet  
        if(processed || --message->lifetime <= 0){
            messagesToProcess.erase(messagesToProcess.begin() + i);
            i--;
        }
    }

    // Insert the remaining frames to update
    for(sp<UpdatingFrame> upFrame : alwaysUptadingFrames)
        toUpdateFrames.insert(upFrame);

    // Updates the frames to update
    for(unordered_set<sp<UpdatingFrame>>::iterator it = toUpdateFrames.begin(); it != toUpdateFrames.end(); it++)
        (*it)->update(); 
}