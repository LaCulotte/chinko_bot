#ifndef VAR_GETVALUE_H
#define VAR_GETVALUE_H

#include "Var.h"
#include <typeinfo>

template<typename T>
T Var<T>::getValue(const IVar& var) {
    switch (var.type)
    {
    case BOOL:
        return *((bool*) var.value);

    case INT8:
        return *((int8_t*) var.value);

    case UINT8:
        return *((uint8_t*) var.value);

    case INT32:
        return *((int32_t*) var.value);

    case UINT32:
        return *((uint32_t*) var.value);

    case DOUBLE:
        return *((double*) var.value);

    case CHAR:
        return *((char*) var.value);

    case STRING:
        throw std::string("Cannot convert type " + IVar::typeToString(var.type) + " to type " + Var<T>::templateToString());
        break;

    case NONE:
        throw std::string("Cannot convert type " + IVar::typeToString(var.type) + " to type " + Var<T>::templateToString());
    }

    return *((T*) var.value);
}

template<>
std::string Var<std::string>::getValue(const IVar& var) {
    switch (var.type)
    {
    case STRING:
        return *((std::string*) var.value);
    
    case CHAR:
        return "" + *((char*) var.value);

    case BOOL:
    case INT8:
    case UINT8:
    case INT32:
    case UINT32:
    case DOUBLE:
        return var.asString();

    default:
        throw std::string("Cannot convert type " + IVar::typeToString(var.type) + " to type std::string");
        break;
    }

    return "";
}

template<typename T>
T Var<T>::getValue(const IVar* var) {
    switch (var->type)
    {
    case BOOL:
        return *((bool*) var->value);

    case INT8:
        return *((int8_t*) var->value);

    case UINT8:
        return *((uint8_t*) var->value);

    case INT32:
        return *((int32_t*) var->value);

    case UINT32:
        return *((uint32_t*) var->value);

    case DOUBLE:
        return *((double*) var->value);

    case CHAR:
        return *((char*) var->value);

    case STRING:
        throw std::string("Cannot convert type " + IVar::typeToString(var->type) + " to type " + Var<T>::templateToString());
        break;

    case NONE:
        throw std::string("Cannot convert type " + IVar::typeToString(var->type) + " to type " + Var<T>::templateToString());
    }

    return *((T*) var->value);
}

template<>
std::string Var<std::string>::getValue(const IVar* var) {
    switch (var->type)
    {
    case STRING:
        return *((std::string*) var->value);
    
    case CHAR:
        return "" + *((char*) var->value);

    case BOOL:
    case INT8:
    case UINT8:
    case INT32:
    case UINT32:
    case DOUBLE:
        return var->asString();

    default:
        throw std::string("Cannot convert type " + IVar::typeToString(var->type) + " to type std::string");
        break;
    }

    return "";
}

template<typename T>
T Var<T>::getValue(sp<IVar> var) {
    switch (var->type)
    {
    case BOOL:
        return *((bool*) var->value);

    case INT8:
        return *((int8_t*) var->value);

    case UINT8:
        return *((uint8_t*) var->value);

    case INT32:
        return *((int32_t*) var->value);

    case UINT32:
        return *((uint32_t*) var->value);

    case DOUBLE:
        return *((double*) var->value);

    case CHAR:
        return *((char*) var->value);

    case STRING:
        throw std::string("Cannot convert type " + IVar::typeToString(var->type) + " to type " + Var<T>::templateToString());
        break;

    case NONE:
        throw std::string("Cannot convert type " + IVar::typeToString(var->type) + " to type " + Var<T>::templateToString());
    }

    return *((T*) var->value);
}

template<>
std::string Var<std::string>::getValue(sp<IVar> var) {
    switch (var->type)
    {
    case STRING:
        return *((std::string*) var->value);
    
    case CHAR:
        return "" + *((char*) var->value);

    case BOOL:
    case INT8:
    case UINT8:
    case INT32:
    case UINT32:
    case DOUBLE:
        return var->asString();

    default:
        throw std::string("Cannot convert type " + IVar::typeToString(var->type) + " to type std::string");
        break;
    }

    return "";
}


#endif