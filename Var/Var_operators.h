#ifndef VAR_COMPATIBILITY_H
#define VAR_COMPATIBILITY_H

#include "Var.h"

#define OPERATION(operator, VarType, this_type, other_type, this_ptr, other_ptr) case VarType: {\
                            auto new_value = Var<this_type>::getValue(this_ptr) operator Var<other_type>::getValue(other_ptr); \
                            return std::make_shared<Var<decltype(new_value)>>(new_value); \
                        } 

#define ASSIGN_OPERATION(operator, VarType, this_type, other_type, this_ptr, other_ptr) case VarType : \
                            this_ptr->setValue(Var<this_type>::getValue(this_ptr) operator Var<other_type>::getValue(other_ptr)); \
                            return *this_ptr;

#define COMPARISON(operator, VarType, this_type, other_type, this_ptr, other_ptr) case VarType : \
                            return (Var<this_type>::getValue(this_ptr) operator Var<other_type>::getValue(other_ptr)); \

template<typename T>
sp<IVar> Var<T>::operator+(const IVar& other) {
    switch (other.type) {
        OPERATION(+, BOOL, T, bool, this, other)
        OPERATION(+, INT8, T, int8_t, this, other)
        OPERATION(+, UINT8, T, uint8_t, this, other)
        OPERATION(+, INT32, T, int32_t, this, other)
        OPERATION(+, UINT32, T, uint32_t, this, other)
        OPERATION(+, DOUBLE, T, double, this, other)
        OPERATION(+, CHAR, T, char, this, other)

        default:
            throw std::string("Cannot add type " + Var<T>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return nullptr;
    }
}
template<> inline
sp<IVar> Var<std::string>::operator+(const IVar& other) {
    switch (other.type) {
        OPERATION(+, CHAR, std::string, char, this, other)
        OPERATION(+, STRING, std::string, std::string, this, other)

        default:
            throw std::string("Cannot add type " + Var<std::string>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return nullptr;
    }
}


template<typename T>
sp<IVar> Var<T>::operator-(const IVar& other) {
    switch (other.type) {
        OPERATION(-, BOOL, T, bool, this, other)
        OPERATION(-, INT8, T, int8_t, this, other)
        OPERATION(-, UINT8, T, uint8_t, this, other)
        OPERATION(-, INT32, T, int32_t, this, other)
        OPERATION(-, UINT32, T, uint32_t, this, other)
        OPERATION(-, DOUBLE, T, double, this, other)
        OPERATION(-, CHAR, T, char, this, other)

        default:
            throw std::string("Cannot substract type " + Var<T>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return nullptr;
    }
}
template<> inline
sp<IVar> Var<std::string>::operator-(const IVar& other) {
    throw std::string("Cannot substract type " + Var<std::string>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
    return nullptr;
}


template<typename T>
sp<IVar> Var<T>::operator*(const IVar& other) {
    switch (other.type) {
        OPERATION(*, BOOL, T, bool, this, other)
        OPERATION(*, INT8, T, int8_t, this, other)
        OPERATION(*, UINT8, T, uint8_t, this, other)
        OPERATION(*, INT32, T, int32_t, this, other)
        OPERATION(*, UINT32, T, uint32_t, this, other)
        OPERATION(*, DOUBLE, T, double, this, other)
        OPERATION(*, CHAR, T, char, this, other)

        default:
            throw std::string("Cannot multiply type " + Var<T>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return nullptr;
    }
}
template<> inline
sp<IVar> Var<std::string>::operator*(const IVar& other) {
    throw std::string("Cannot multiply type " + Var<std::string>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
    return nullptr;
}


template<typename T>
sp<IVar> Var<T>::operator/(const IVar& other) {
    switch (other.type) {
        OPERATION(/, BOOL, T, bool, this, other)
        OPERATION(/, INT8, T, int8_t, this, other)
        OPERATION(/, UINT8, T, uint8_t, this, other)
        OPERATION(/, INT32, T, int32_t, this, other)
        OPERATION(/, UINT32, T, uint32_t, this, other)
        OPERATION(/, DOUBLE, T, double, this, other)
        OPERATION(/, CHAR, T, char, this, other)

        default:
            throw std::string("Cannot divide type " + Var<T>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return nullptr;
    }
}
template<> inline
sp<IVar> Var<std::string>::operator/(const IVar& other) {
    throw std::string("Cannot divide type " + Var<std::string>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
    return nullptr;
}


template<typename T>
sp<IVar> Var<T>::operator%(const IVar& other) {
    switch (other.type) {
        OPERATION(%, BOOL, T, bool, this, other)
        OPERATION(%, INT8, T, int8_t, this, other)
        OPERATION(%, UINT8, T, uint8_t, this, other)
        OPERATION(%, INT32, T, int32_t, this, other)
        OPERATION(%, UINT32, T, uint32_t, this, other)
        OPERATION(%, CHAR, T, char, this, other)

        default:
            throw std::string("Cannot modulo type " + Var<T>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return nullptr;
    }
}
template<> inline
sp<IVar> Var<std::string>::operator%(const IVar& other) {
    throw std::string("Cannot modulo type " + Var<std::string>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
    return nullptr;
}
template<> inline
sp<IVar> Var<double>::operator%(const IVar& other) {
    throw std::string("Cannot modulo type " + Var<double>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
    return nullptr;
}


template<typename T>
sp<IVar> Var<T>::operator&(const IVar& other) {
    switch (other.type) {
        OPERATION(&, BOOL, T, bool, this, other)
        OPERATION(&, INT8, T, int8_t, this, other)
        OPERATION(&, UINT8, T, uint8_t, this, other)
        OPERATION(&, INT32, T, int32_t, this, other)
        OPERATION(&, UINT32, T, uint32_t, this, other)
        OPERATION(&, CHAR, T, char, this, other)

        default:
            throw std::string("Cannot and type " + Var<T>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return nullptr;
    }
}
template<> inline
sp<IVar> Var<std::string>::operator&(const IVar& other) {
    throw std::string("Cannot and type " + Var<std::string>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
    return nullptr;
}
template<> inline
sp<IVar> Var<double>::operator&(const IVar& other) {
    throw std::string("Cannot and type " + Var<double>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
    return nullptr;
}


template<typename T>
sp<IVar> Var<T>::operator|(const IVar& other) {
    switch (other.type) {
        OPERATION(|, BOOL, T, bool, this, other)
        OPERATION(|, INT8, T, int8_t, this, other)
        OPERATION(|, UINT8, T, uint8_t, this, other)
        OPERATION(|, INT32, T, int32_t, this, other)
        OPERATION(|, UINT32, T, uint32_t, this, other)
        OPERATION(|, CHAR, T, char, this, other)

        default:
            throw std::string("Cannot or type " + Var<T>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return nullptr;
    }
}
template<> inline
sp<IVar> Var<std::string>::operator|(const IVar& other) {
    throw std::string("Cannot or type " + Var<std::string>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
    return nullptr;
}
template<> inline
sp<IVar> Var<double>::operator|(const IVar& other) {
    throw std::string("Cannot or type " + Var<double>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
    return nullptr;
}


template<typename T>
sp<IVar> Var<T>::operator^(const IVar& other) {
    switch (other.type) {
        OPERATION(^, BOOL, T, bool, this, other)
        OPERATION(^, INT8, T, int8_t, this, other)
        OPERATION(^, UINT8, T, uint8_t, this, other)
        OPERATION(^, INT32, T, int32_t, this, other)
        OPERATION(^, UINT32, T, uint32_t, this, other)
        OPERATION(^, CHAR, T, char, this, other)

        default:
            throw std::string("Cannot xor type " + Var<T>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return nullptr;
    }
}
template<> inline
sp<IVar> Var<std::string>::operator^(const IVar& other) {
    throw std::string("Cannot xor type " + Var<std::string>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
    return nullptr;
}
template<> inline
sp<IVar> Var<double>::operator^(const IVar& other) {
    throw std::string("Cannot xor type " + Var<double>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
    return nullptr;
}

template<typename T>
IVar& Var<T>::operator+=(const IVar& other) {
    switch (other.type) {
        ASSIGN_OPERATION(+, BOOL, T, bool, this, other)
        ASSIGN_OPERATION(+, INT8, T, int8_t, this, other)
        ASSIGN_OPERATION(+, UINT8, T, uint8_t, this, other)
        ASSIGN_OPERATION(+, INT32, T, int32_t, this, other)
        ASSIGN_OPERATION(+, UINT32, T, uint32_t, this, other)
        ASSIGN_OPERATION(+, DOUBLE, T, double, this, other)
        ASSIGN_OPERATION(+, CHAR, T, char, this, other)

        default:
            throw std::string("Cannot add type " + Var<T>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return *this;
    }
}
template<> inline
IVar& Var<std::string>::operator+=(const IVar& other) {
    switch (other.type) {
        ASSIGN_OPERATION(+, CHAR, std::string, char, this, other)
        ASSIGN_OPERATION(+, STRING, std::string, std::string, this, other)

        default:
            throw std::string("Cannot add type " + Var<std::string>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return *this;
    }
}


template<typename T>
IVar& Var<T>::operator-=(const IVar& other) {
    switch (other.type) {
        ASSIGN_OPERATION(-, BOOL, T, bool, this, other)
        ASSIGN_OPERATION(-, INT8, T, int8_t, this, other)
        ASSIGN_OPERATION(-, UINT8, T, uint8_t, this, other)
        ASSIGN_OPERATION(-, INT32, T, int32_t, this, other)
        ASSIGN_OPERATION(-, UINT32, T, uint32_t, this, other)
        ASSIGN_OPERATION(-, DOUBLE, T, double, this, other)
        ASSIGN_OPERATION(-, CHAR, T, char, this, other)

        default:
            throw std::string("Cannot substract type " + Var<T>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return *this;
    }
}
template<> inline
IVar& Var<std::string>::operator-=(const IVar& other) {
    throw std::string("Cannot substract type " + Var<std::string>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
    return *this;
}


template<typename T>
IVar& Var<T>::operator*=(const IVar& other) {
    switch (other.type) {
        ASSIGN_OPERATION(*, BOOL, T, bool, this, other)
        ASSIGN_OPERATION(*, INT8, T, int8_t, this, other)
        ASSIGN_OPERATION(*, UINT8, T, uint8_t, this, other)
        ASSIGN_OPERATION(*, INT32, T, int32_t, this, other)
        ASSIGN_OPERATION(*, UINT32, T, uint32_t, this, other)
        ASSIGN_OPERATION(*, DOUBLE, T, double, this, other)
        ASSIGN_OPERATION(*, CHAR, T, char, this, other)

        default:
            throw std::string("Cannot multiply type " + Var<T>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return *this;
    }
}
template<> inline
IVar& Var<std::string>::operator*=(const IVar& other) {
    throw std::string("Cannot multiply type " + Var<std::string>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
    return *this;
}


template<typename T>
IVar& Var<T>::operator/=(const IVar& other) {
    switch (other.type) {
        ASSIGN_OPERATION(/, BOOL, T, bool, this, other)
        ASSIGN_OPERATION(/, INT8, T, int8_t, this, other)
        ASSIGN_OPERATION(/, UINT8, T, uint8_t, this, other)
        ASSIGN_OPERATION(/, INT32, T, int32_t, this, other)
        ASSIGN_OPERATION(/, UINT32, T, uint32_t, this, other)
        ASSIGN_OPERATION(/, DOUBLE, T, double, this, other)
        ASSIGN_OPERATION(/, CHAR, T, char, this, other)

        default:
            throw std::string("Cannot divide type " + Var<T>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return *this;
    }
}
template<> inline
IVar& Var<std::string>::operator/=(const IVar& other) {
    throw std::string("Cannot divide type " + Var<std::string>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
    return *this;
}


template<typename T>
IVar& Var<T>::operator%=(const IVar& other) {
    switch (other.type) {
        ASSIGN_OPERATION(%, BOOL, T, bool, this, other)
        ASSIGN_OPERATION(%, INT8, T, int8_t, this, other)
        ASSIGN_OPERATION(%, UINT8, T, uint8_t, this, other)
        ASSIGN_OPERATION(%, INT32, T, int32_t, this, other)
        ASSIGN_OPERATION(%, UINT32, T, uint32_t, this, other)
        ASSIGN_OPERATION(%, CHAR, T, char, this, other)

        default:
            throw std::string("Cannot modulo type " + Var<T>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return *this;
    }
}
template<> inline
IVar& Var<std::string>::operator%=(const IVar& other) {
    throw std::string("Cannot modulo type " + Var<std::string>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
    return *this;
}
template<> inline
IVar& Var<double>::operator%=(const IVar& other) {
    throw std::string("Cannot modulo type " + Var<double>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
    return *this;
}

template<typename T>
IVar& Var<T>::operator&=(const IVar& other) {
    switch (other.type) {
        ASSIGN_OPERATION(&, BOOL, T, bool, this, other)
        ASSIGN_OPERATION(&, INT8, T, int8_t, this, other)
        ASSIGN_OPERATION(&, UINT8, T, uint8_t, this, other)
        ASSIGN_OPERATION(&, INT32, T, int32_t, this, other)
        ASSIGN_OPERATION(&, UINT32, T, uint32_t, this, other)
        ASSIGN_OPERATION(&, CHAR, T, char, this, other)

        default:
            throw std::string("Cannot and type " + Var<T>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return *this;
    }
}
template<> inline
IVar& Var<std::string>::operator&=(const IVar& other) {
    throw std::string("Cannot and type " + Var<std::string>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
    return *this;
}
template<> inline
IVar& Var<double>::operator&=(const IVar& other) {
    throw std::string("Cannot and type " + Var<double>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
    return *this;
}


template<typename T>
IVar& Var<T>::operator|=(const IVar& other) {
    switch (other.type) {
        ASSIGN_OPERATION(|, BOOL, T, bool, this, other)
        ASSIGN_OPERATION(|, INT8, T, int8_t, this, other)
        ASSIGN_OPERATION(|, UINT8, T, uint8_t, this, other)
        ASSIGN_OPERATION(|, INT32, T, int32_t, this, other)
        ASSIGN_OPERATION(|, UINT32, T, uint32_t, this, other)
        ASSIGN_OPERATION(|, CHAR, T, char, this, other)

        default:
            throw std::string("Cannot or type " + Var<T>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return *this;
    }
}
template<> inline
IVar& Var<std::string>::operator|=(const IVar& other) {
    throw std::string("Cannot or type " + Var<std::string>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
    return *this;
}
template<> inline
IVar& Var<double>::operator|=(const IVar& other) {
    throw std::string("Cannot or type " + Var<double>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
    return *this;
}


template<typename T>
IVar& Var<T>::operator^=(const IVar& other) {
    switch (other.type) {
        ASSIGN_OPERATION(^, BOOL, T, bool, this, other)
        ASSIGN_OPERATION(^, INT8, T, int8_t, this, other)
        ASSIGN_OPERATION(^, UINT8, T, uint8_t, this, other)
        ASSIGN_OPERATION(^, INT32, T, int32_t, this, other)
        ASSIGN_OPERATION(^, UINT32, T, uint32_t, this, other)
        ASSIGN_OPERATION(^, CHAR, T, char, this, other)

        default:
            throw std::string("Cannot xor type " + Var<T>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return *this;
    }
}
template<> inline
IVar& Var<std::string>::operator^=(const IVar& other) {
    throw std::string("Cannot xor type " + Var<std::string>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
    return *this;
}
template<> inline
IVar& Var<double>::operator^=(const IVar& other) {
    throw std::string("Cannot xor type " + Var<double>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
    return *this;
}


template<typename T>
bool Var<T>::operator==(const IVar& other) {
    switch (other.type) {
        COMPARISON(==, BOOL, T, bool, this, other)
        COMPARISON(==, INT8, T, int8_t, this, other)
        COMPARISON(==, UINT8, T, uint8_t, this, other)
        COMPARISON(==, INT32, T, int32_t, this, other)
        COMPARISON(==, UINT32, T, uint32_t, this, other)
        COMPARISON(==, DOUBLE, T, double, this, other)
        COMPARISON(==, CHAR, T, char, this, other)

        case STRING:
        case NONE:
            throw std::string("Cannot compare type " + Var<T>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return false;
    }

    return false;
}
template<> inline
bool Var<std::string>::operator==(const IVar& other) {
    switch (other.type) {
        COMPARISON(==, STRING, std::string, std::string, this, other)
        default:
            throw std::string("Cannot compare type " + Var<std::string>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return false;
    }

    return false;
}


template<typename T>
bool Var<T>::operator<=(const IVar& other) {
    switch (other.type) {
        COMPARISON(<=, BOOL, T, bool, this, other)
        COMPARISON(<=, INT8, T, int8_t, this, other)
        COMPARISON(<=, UINT8, T, uint8_t, this, other)
        COMPARISON(<=, INT32, T, int32_t, this, other)
        COMPARISON(<=, UINT32, T, uint32_t, this, other)
        COMPARISON(<=, DOUBLE, T, double, this, other)
        COMPARISON(<=, CHAR, T, char, this, other)

        case STRING:
        case NONE:
            throw std::string("Cannot compare type " + Var<T>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return false;
    }

    return false;
}
template<> inline
bool Var<std::string>::operator<=(const IVar& other) {
    switch (other.type) {
        COMPARISON(<=, STRING, std::string, std::string, this, other)
        default:
            throw std::string("Cannot compare type " + Var<std::string>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return false;
    }

    return false;
}


template<typename T>
bool Var<T>::operator>=(const IVar& other) {
    switch (other.type) {
        COMPARISON(>=, BOOL, T, bool, this, other)
        COMPARISON(>=, INT8, T, int8_t, this, other)
        COMPARISON(>=, UINT8, T, uint8_t, this, other)
        COMPARISON(>=, INT32, T, int32_t, this, other)
        COMPARISON(>=, UINT32, T, uint32_t, this, other)
        COMPARISON(>=, DOUBLE, T, double, this, other)
        COMPARISON(>=, CHAR, T, char, this, other)

        case STRING:
        case NONE:
            throw std::string("Cannot compare type " + Var<T>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return false;
    }

    return false;
}
template<> inline
bool Var<std::string>::operator>=(const IVar& other) {
    switch (other.type) {
        COMPARISON(>=, STRING, std::string, std::string, this, other)
        default:
            throw std::string("Cannot compare type " + Var<std::string>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return false;
    }

    return false;
}


template<typename T>
bool Var<T>::operator>(const IVar& other) {
    switch (other.type) {
        COMPARISON(>, BOOL, T, bool, this, other)
        COMPARISON(>, INT8, T, int8_t, this, other)
        COMPARISON(>, UINT8, T, uint8_t, this, other)
        COMPARISON(>, INT32, T, int32_t, this, other)
        COMPARISON(>, UINT32, T, uint32_t, this, other)
        COMPARISON(>, DOUBLE, T, double, this, other)
        COMPARISON(>, CHAR, T, char, this, other)

        case STRING:
        case NONE:
            throw std::string("Cannot compare type " + Var<T>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return false;
    }

    return false;
}
template<> inline
bool Var<std::string>::operator>(const IVar& other) {
    switch (other.type) {
        COMPARISON(>, STRING, std::string, std::string, this, other)
        default:
            throw std::string("Cannot compare type " + Var<std::string>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return false;
    }

    return false;
}


template<typename T>
bool Var<T>::operator<(const IVar& other) {
    switch (other.type) {
        COMPARISON(<, BOOL, T, bool, this, other)
        COMPARISON(<, INT8, T, int8_t, this, other)
        COMPARISON(<, UINT8, T, uint8_t, this, other)
        COMPARISON(<, INT32, T, int32_t, this, other)
        COMPARISON(<, UINT32, T, uint32_t, this, other)
        COMPARISON(<, DOUBLE, T, double, this, other)
        COMPARISON(<, CHAR, T, char, this, other)

        case STRING:
        case NONE:
            throw std::string("Cannot compare type " + Var<T>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return false;
    }

    return false;
}
template<> inline
bool Var<std::string>::operator<(const IVar& other) {
    switch (other.type) {
        COMPARISON(<, STRING, std::string, std::string, this, other)
        default:
            throw std::string("Cannot compare type " + Var<std::string>::templateToString() + " with type " + IVar::typeToString(other.type) + ".");
            return false;
    }

    return false;
}

#endif