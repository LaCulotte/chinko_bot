#ifndef VAR_CONSTRUCTOR_H
#define VAR_CONSTRUCTOR_H

#include "Var.h"

template<> inline
Var<bool>::Var(bool value) {
    this->value = new bool(value);
    this->type = BOOL;
}

template<> inline
Var<int8_t>::Var(int8_t value) {
    this->value = new int8_t(value);
    this->type = INT8;
}

template<> inline
Var<uint8_t>::Var(uint8_t value) {
    this->value = new uint8_t(value);
    this->type = UINT8;
}

template<> inline
Var<int32_t>::Var(int32_t value) {
    this->value = new int32_t(value);
    this->type = INT32;
}

template<> inline
Var<uint32_t>::Var(uint32_t value) {
    this->value = new uint32_t(value);
    this->type = UINT32;
}

template<> inline
Var<double>::Var(double value) {
    this->value = new double(value);
    this->type = DOUBLE;
}

template<> inline
Var<char>::Var(char value) {
    this->value = new char(value);
    this->type = CHAR;
}

template<> inline
Var<std::string>::Var(std::string value) {
    this->value = new std::string(value);
    this->type = STRING;
}

#endif