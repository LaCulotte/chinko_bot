#ifndef GAMESERVERINFO_H
#define GAMESERVERINFO_H

#include "NetworkType.h"

class GameServerInfo : public NetworkType {
public:
    // Constructor
    GameServerInfo() {};
    // Copy constructor
    GameServerInfo(const GameServerInfo& other) = default;

    // Copy operator
    GameServerInfo& operator=(const GameServerInfo& other) = default;
    // Destructor
    ~GameServerInfo() = default;

    // Returns the type's id
    virtual unsigned int getId() { return typeId; };
    // Type's id
    static const unsigned int typeId = 25;

    bool serialize(sp<MessageDataBuffer> output) override;
    bool deserialize(sp<MessageDataBuffer> input) override;

    bool isMonoAccount = false;
    bool isSelectable = false;

    int id;
    int type;
    int status;
    int completion;

    int charactersCount;
    int charactersSlots;

    double date;
};

#endif