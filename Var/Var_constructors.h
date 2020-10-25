#ifndef VAR_CONSTRUCTOR_H
#define VAR_CONSTRUCTOR_H

#include "Var.h"

template<typename T>
Var<T>::Var(const Var<T>& other) {
    this->delete_value();

    this->value = other.get_value_copy();
    this->initType();
}

template<typename T>
Var<T>& Var<T>::operator=(const Var<T>& other) {
    this->delete_value();

    this->value = other.get_value_copy();

    return *this;
}

template<typename T>
Var<T>::Var(const IVar& other) {
    this->initType();
    this->value = new T(Var<T>::getValue(other));
}

template<typename T>
Var<T>& Var<T>::operator=(const IVar& other) {
    *((T*) this->value) = Var<T>::getValue(other);
}

template<typename T>
Var<T>::Var(T value) {
    this->initType();
    this->value = new T(value);
}

template<> inline
void Var<bool>::initType() {
    this->type = BOOL;
}

template<> inline
void Var<int8_t>::initType() {
    this->type = INT8;
}

template<> inline
void Var<uint8_t>::initType() {
    this->type = UINT8;
}

template<> inline
void Var<int32_t>::initType() {
    this->type = INT32;
}

template<> inline
void Var<uint32_t>::initType() {
    this->type = UINT32;
}

template<> inline
void Var<double>::initType() {
    this->type = DOUBLE;
}

template<> inline
void Var<char>::initType() {
    this->type = CHAR;
}

template<> inline
void Var<std::string>::initType() {
    this->type = STRING;
}

template<typename T>
void Var<T>::initType() {
    this->type = NONE;
}

#endif