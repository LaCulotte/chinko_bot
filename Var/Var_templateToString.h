#ifndef VAR_TEMPLATE_TO_STRING_H
#define VAR_TEMPLATE_TO_STRING_H

#include "Var.h"

template<> inline std::string Var<bool>::templateToString()        { return "bool"; };
template<> inline std::string Var<int8_t>::templateToString()      { return "int8_t"; };
template<> inline std::string Var<uint8_t>::templateToString()     { return "uint8_t"; };
template<> inline std::string Var<int32_t>::templateToString()     { return "int32_t"; };
template<> inline std::string Var<uint32_t>::templateToString()    { return "uint32_t"; };
template<> inline std::string Var<double>::templateToString()      { return "double"; };
template<> inline std::string Var<char>::templateToString()        { return "char"; };
template<> inline std::string Var<std::string>::templateToString() { return "std::string"; };
template<typename T> std::string Var<T>::templateToString() { return "undifined"; };

#endif