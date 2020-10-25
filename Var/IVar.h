#ifndef IVAR_H
#define IVAR_H

#include <string>
#include <cstring>
#include <iostream>

#include <memory>
#define sp std::shared_ptr

#define COPY_DATA_FROM_POINTER_TO(asType, origin_ptr, destination_ptr) destination_ptr = malloc(sizeof(asType)); memcpy(destination_ptr, origin_ptr, sizeof(asType));

enum VarType{
    NONE,
    BOOL,
    INT8,
    UINT8,
    INT32,
    UINT32,
    DOUBLE,
    CHAR,
    STRING
};

class IVar {
protected:
    IVar() {};
public:
    ~IVar() {};

    IVar(const IVar& other);
    IVar& operator=(const IVar& other);
    // IVar(IVar&& other);
    // IVar& operator=(IVar&& other);

    void* get_value_copy() const;
    virtual void delete_value() {};

    VarType get_type() { return this->type; }

    // virtual bool isCompatibleWith_Assignement   (VarType otherType) { return false; };
    virtual bool isCompatibleWith_Modulo        (VarType otherType) { return false; };
    virtual bool isCompatibleWith_Addition    (VarType otherType) { return false; };
    virtual bool isCompatibleWith_Operations    (VarType otherType) { return false; };
    virtual bool isCompatibleWith_Bitwise       (VarType otherType) { return false; };
    virtual bool isCompatibleWith_Comparison    (VarType otherType) { return false; };
    // virtual bool isCompatibleWith_Cast          (VarType otherType) { return false; };

    virtual sp<IVar> operator+(const IVar& other) { throw std::string("Invalid Cannot + : variable. IVar cannot be used."); return nullptr; };
    virtual sp<IVar> operator-(const IVar& other) { throw std::string("Invalid Cannot - : variable. IVar cannot be used."); return nullptr; };
    virtual sp<IVar> operator*(const IVar& other) { throw std::string("Invalid Cannot * : variable. IVar cannot be used."); return nullptr; };
    virtual sp<IVar> operator/(const IVar& other) { throw std::string("Invalid Cannot / : variable. IVar cannot be used."); return nullptr; };
    virtual sp<IVar> operator%(const IVar& other) { throw std::string("Invalid Cannot % : variable. IVar cannot be used."); return nullptr; };
    virtual sp<IVar> operator|(const IVar& other) { throw std::string("Invalid Cannot | : variable. IVar cannot be used."); return nullptr; };
    virtual sp<IVar> operator&(const IVar& other) { throw std::string("Invalid Cannot & : variable. IVar cannot be used."); return nullptr; };
    virtual sp<IVar> operator^(const IVar& other) { throw std::string("Invalid Cannot ^ : variable. IVar cannot be used."); return nullptr; };
    
    virtual IVar& operator+=(const IVar& other) { throw std::string("Cannot += : Invalid variable. IVar cannot be used."); return *this; };
    virtual IVar& operator-=(const IVar& other) { throw std::string("Cannot -= : Invalid variable. IVar cannot be used."); return *this; };
    virtual IVar& operator*=(const IVar& other) { throw std::string("Cannot *= : Invalid variable. IVar cannot be used."); return *this; };
    virtual IVar& operator/=(const IVar& other) { throw std::string("Cannot /= : Invalid variable. IVar cannot be used."); return *this; };
    virtual IVar& operator%=(const IVar& other) { throw std::string("Cannot %= : Invalid variable. IVar cannot be used."); return *this; };
    virtual IVar& operator|=(const IVar& other) { throw std::string("Cannot |= : Invalid variable. IVar cannot be used."); return *this; };
    virtual IVar& operator&=(const IVar& other) { throw std::string("Cannot &= : Invalid variable. IVar cannot be used."); return *this; };
    virtual IVar& operator^=(const IVar& other) { throw std::string("Cannot ^= : Invalid variable. IVar cannot be used."); return *this; };

    virtual bool operator==(const IVar& other) { throw std::string("Cannot == : Invalid variable. IVar cannot be used."); return false; };
    virtual bool operator> (const IVar& other) { throw std::string("Cannot >  : Invalid variable. IVar cannot be used."); return false; };
    virtual bool operator< (const IVar& other) { throw std::string("Cannot <  : Invalid variable. IVar cannot be used."); return false; };
    virtual bool operator<=(const IVar& other) { throw std::string("Cannot <= : Invalid variable. IVar cannot be used."); return false; };
    virtual bool operator>=(const IVar& other) { throw std::string("Cannot >= : Invalid variable. IVar cannot be used."); return false; };

    // virtual bool operator&&(const IVar& other) { throw std::string("Cannot && : Invalid variable. IVar cannot be used."); return false; };
    // virtual bool operator||(const IVar& other) { throw std::string("Cannot || : Invalid variable. IVar cannot be used."); return false; };
    // virtual bool operator!()     { throw std::string("Cannot ! : Invalid variable. IVar cannot be used."); return false; };
    virtual operator bool() const   { throw std::string("Cannot bool : Invalid variable. IVar cannot be used."); return false; };

    virtual std::string asString() const { throw std::string("Cannot String : Invalid variable. IVar cannot be used."); return ""; };
    friend std::ostream& operator<<(std::ostream& os, const IVar& var) { os << var.asString(); return os; }

    static std::string typeToString(VarType type);

public:
    VarType type = NONE;
    void* value = nullptr;
};

#endif