#ifndef VAR_TEMPLATE_TO_STRING_H
#define VAR_TEMPLATE_TO_STRING_H

#include "Var.h"

template<> std::string Var<bool>::templateToString()        { return "bool"; };
template<> std::string Var<int8_t>::templateToString()      { return "int8_t"; };
template<> std::string Var<uint8_t>::templateToString()     { return "uint8_t"; };
template<> std::string Var<int32_t>::templateToString()     { return "int32_t"; };
template<> std::string Var<uint32_t>::templateToString()    { return "uint32_t"; };
template<> std::string Var<double>::templateToString()      { return "double"; };
template<> std::string Var<char>::templateToString()        { return "char"; };
template<> std::string Var<std::string>::templateToString() { return "std::string"; };
template<typename T> std::string Var<T>::templateToString() { return "undifined"; };

#endif