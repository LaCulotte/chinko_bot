#ifndef NETWORKTYPE_HANDLER_H
#define NETWORKTYPE_HANDLER_H

#include <unordered_map>
#include <functional>

#include "NetworkType.h"

class NetworkTypeHandler {
public:
    static NetworkTypeHandler* getInstance();

    sp<NetworkType> getTypeById(int id);

private:
    NetworkTypeHandler();
    ~NetworkTypeHandler() = default;

    static NetworkTypeHandler* typeHandler;

    unordered_map<int, function<sp<NetworkType>()>> id_to_builder;
};

#endif