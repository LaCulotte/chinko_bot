#include "PrefixNetworkConnection.h"

PrefixNetworkConnection::PrefixNetworkConnection() : NetworkConnection() {
    connectionDescription = "PrefixConnection";
}

PrefixNetworkConnection::PrefixNetworkConnection(const PrefixNetworkConnection& other) : NetworkConnection(other) { 
    messageTypeHandler = other.messageTypeHandler;
}

PrefixNetworkConnection& PrefixNetworkConnection::operator=(const PrefixNetworkConnection& other){
    messageTypeHandler = other.messageTypeHandler;
    return *this;
}

void PrefixNetworkConnection::resetPending(){
    // All the pending variables are reset
    pendingDataFinalLength = 0;
    pendingData.reset();
    pendingMessage.reset();
    pending = false;
}

sp<ConnectionMessage> PrefixNetworkConnection::readMessage() {
    if(!pending){
        // If there is no pending message

        // Reads the prefix of the current message
        sp<MessageDataBuffer> prefixData = readPrefix();

        if(prefixData){
            // Turns the prefix data into a message
            sp<PrefixedMessage> message = deserializePrefix(prefixData);

            if(!message){
                // If the prefix data is invalid

                // Logs error
                Logger::write("The prefix read is not compatible with the type of PrefixedMessage used.", LOG_ERROR);
                Logger::write("Emptying socket buffer. Future data may be messed up", LOG_ERROR);

                // Empties the socket's buffer
                emptySocketBuffer();

                return nullptr;
            }

            if(message->getLength() > 0) {
                // Reads any complementary data necessary to completly build the message
                sp<MessageDataBuffer> contentData = readData(message->getLength());

                if(!contentData){
                    // Logs potential error
                    Logger::write("Error while reading content data for a message. Message id : " + to_string(message->getId()) + "; length : " + to_string(message->getLength()) + "b.");

                    return nullptr;
                }

                if(contentData->size() < message->getLength()){
                    // If there is not enougth data to read, puts the current message and data to pending
                    
                    pending = true;
                    pendingData = contentData;
                    pendingDataFinalLength = message->getLength();
                    pendingMessage = message;
                    timeLastPendingUpdate = chrono::system_clock::now();

                    // Logs state and returns
                    Logger::write("Message too long; Connection state switched to pending");
                    return nullptr;
                }

                // Tries to build the message
                if(!message->deserialize(contentData)){
                    // Logs potential error
                    Logger::write("Could not deserialize data to message. Message id : " + to_string(message->getId()) + "; length : " + to_string(message->getLength()) + " Bytes.");

                    return nullptr;
                }
            }

            return message;
        } else {
            return nullptr;
        }

    } else {
        // If there is a pending message

        // Gets time since the last time pending data was read
        auto timeBetweenPendingUpdates = chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now() - timeLastPendingUpdate);
        if(!maxTimeBetweenPendingUpdates || timeBetweenPendingUpdates < *maxTimeBetweenPendingUpdates){
            // If this time is short enougth
            
            int rLength = pendingDataFinalLength - pendingData->size();

            // Tries to read the remaining data
            sp<MessageDataBuffer> contentData = readData(rLength);

            if(!contentData)
                return nullptr;

            // Push it at the end of 'pendingData' if it could be read
            pendingData->push(contentData->getData());

            if(contentData->size() == rLength){
                // If all the data was read

                sp<PrefixedMessage> rMessage(nullptr);
                // Tries to build the message
                if(pendingMessage->deserialize(pendingData)) {
                    rMessage = pendingMessage;    
                }

                // Exits pending state
                resetPending();

                return rMessage;
            } else {
                // If there is still data to read, update the time of the last pending data read
                timeLastPendingUpdate = chrono::system_clock::now();

                return nullptr;
            }
                
        } else {
            // If the time since last pending data read id too long

            // Logs
            Logger::write("Message could not be read entirely, 'low' data did not arrive. Received data length : " + to_string(pendingData->size()) + "; Expected data length : " + to_string(pendingDataFinalLength) + "; Message id " + to_string(pendingMessage->getId()) + ".", LOG_IMPORTANT_WARNING);

            // Exits pending state
            resetPending();

            // Return next message
            return readMessage();
        }
    }
}

vector<sp<ConnectionMessage>> PrefixNetworkConnection::readMessages(int n, bool fill) {
    // Returning vector
    vector<sp<ConnectionMessage>> ret;

    // Reads messages while there are messages to read, and the returning vector has less than n messages 
    sp<ConnectionMessage> msg = readMessage();
    while(msg && ret.size() < n){
        ret.push_back(msg);
        msg = readMessage();
    }

    // If the caller want a returning vector with exactly n messages, fills the returning vector with nullptr
    if(fill)
        for(int i = ret.size(); i < n; i++){
            ret.push_back(nullptr);
        }

    return ret;
}

vector<sp<ConnectionMessage>> PrefixNetworkConnection::readAllMessages() {
    // Returning vector
    vector<sp<ConnectionMessage>> ret;

    // Reads messages while there are messages to read, and the returning vector has less than n messages 
    sp<ConnectionMessage> msg = readMessage();
    while(msg){
        ret.push_back(msg);
        msg = readMessage();
    }

    return ret;
}

bool PrefixNetworkConnection::sendMessage(sp<ConnectionMessage> message) {
    // Checks if the message to send id a Prefixed message
    sp<PrefixedMessage> prMessage = dynamic_pointer_cast<PrefixedMessage>(message);
    if(!prMessage){
        // If not, logs the error and returns
        Logger::write("Tried to send a non prefixed-message throught a PrefixNetworkConnection. Message will not be sent.", LOG_WARNING);
        Logger::write("Message id : " + to_string(prMessage->getId()) + ".", LOG_WARNING);

        return false;
    }

    // Data to send
    sp<MessageDataBuffer> output(new MessageDataBuffer());

    // Tries to build the data to read from the message
    if(!prMessage->serialize(output)){
        // If there is an error, logs it and return
        Logger::write("Could not serialize the current message. Message will not be sent", LOG_WARNING);
        Logger::write("Message id : " + to_string(prMessage->getId()) + ".", LOG_WARNING);

        return false;
    }
    
    // Tries to build the prefix from the message
    if(!serializePrefix(output, prMessage)) {
        // If there is an error, logs it and return
        Logger::write("Could not serialize the prefix of the current message. Message will not be sent.", LOG_WARNING);
        Logger::write("Message id : " + to_string(prMessage->getId()) + ".", LOG_WARNING);
        return false;
    }

    // Sends built data
    return writeData(output);
}