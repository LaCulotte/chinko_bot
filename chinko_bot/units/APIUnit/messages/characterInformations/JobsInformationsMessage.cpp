#include "JobsInformationsMessage.h"

bool JobsInformationsMessage::serialize(sp<MessageDataBuffer> output) {
    output->writeShort(jobs.size());
    for(int i = 0; i < jobs.size(); i++)
        if(!jobs[i].serialize(output))
            return false;

    return true;
}

bool JobsInformationsMessage::deserialize(sp<MessageDataBuffer> input) {
    int size = input->readShort();
    for(int i = 0; i < size; i++) {
        JobInformations job;
        if(!job.deserialize(input))
            return false;

        jobs.push_back(job);
    }
    
    return true;
}