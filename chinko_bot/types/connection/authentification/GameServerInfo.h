#ifndef GAMESERVERINFO_H
#define GAMESERVERINFO_H

#include "ptr_include.h"
#include "MessageDataBuffer.h"

class GameServerInfo {
public:
    // Constructor
    GameServerInfo() {};
    // Copy constructor
    GameServerInfo(const GameServerInfo& other) = default;

    // Copy operator
    GameServerInfo& operator=(const GameServerInfo& other) = default;
    // Destructor
    ~GameServerInfo() = default;

    void serialize(sp<MessageDataBuffer> output);
    void deserialize(sp<MessageDataBuffer> input);

    bool isMonoAccount = false;
    bool isSelectable = false;

    int id;
    int type;
    int status;
    int completion;

    int charactersCount;
    int charactersSlots;

    uint64_t date;
};

#endif