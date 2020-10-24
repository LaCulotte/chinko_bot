#ifndef APITYPES_HANDLER_H
#define APITYPES_HANDLER_H

#include <unordered_map>
#include <functional>

#include "APIType.h"

class APITypeHandler {
public:
    static APITypeHandler* getInstance();

    sp<APIType> getTypeById(int id);

private:
    APITypeHandler();
    ~APITypeHandler() = default;

    static APITypeHandler* typeHandler;

    unordered_map<int, function<sp<APIType>()>> id_to_builder;
};

#endif