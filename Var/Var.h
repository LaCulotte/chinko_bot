#ifndef VAR_H
#define VAR_H

#include "IVar.h"

template<typename T>
class Var : public IVar {
public:
    Var(T value) {};
    ~Var() { this->delete_value(); };

    Var<T>(const Var<T>& other) {};
    Var<T>& operator=(const Var<T>& other) {};
    Var<T>(Var<T>&& other) {};
    Var<T>& operator=(Var<T>&& other) {};

    Var<T>(const IVar& other) {};
    Var<T>& operator=(const IVar& other) {};
    
    virtual sp<IVar> operator+(const IVar& other) override;
    virtual sp<IVar> operator-(const IVar& other) override;
    virtual sp<IVar> operator*(const IVar& other) override;
    virtual sp<IVar> operator/(const IVar& other) override;
    virtual sp<IVar> operator%(const IVar& other) override;
    virtual sp<IVar> operator|(const IVar& other) override;
    virtual sp<IVar> operator&(const IVar& other) override;
    virtual sp<IVar> operator^(const IVar& other) override;

    virtual IVar& operator+=(const IVar& other) override;
    virtual IVar& operator-=(const IVar& other) override;
    virtual IVar& operator*=(const IVar& other) override;
    virtual IVar& operator/=(const IVar& other) override;
    virtual IVar& operator%=(const IVar& other) override;
    virtual IVar& operator|=(const IVar& other) override;
    virtual IVar& operator&=(const IVar& other) override;
    virtual IVar& operator^=(const IVar& other) override;

    virtual bool operator==(const IVar& other) override;
    virtual bool operator> (const IVar& other) override;
    virtual bool operator< (const IVar& other) override;
    virtual bool operator<=(const IVar& other) override;
    virtual bool operator>=(const IVar& other) override;

    virtual std::string asString() const override { return std::to_string(Var<T>::getValue(*this)); }
    static std::string templateToString();

    virtual void delete_value() override { if(this->value) delete (T*) this->value; };

    static T getValue(const IVar *var);
    static T getValue(sp<IVar> var);
    static T getValue(const IVar& var);

    void setValue(T value);
};

template<typename T>
void Var<T>::setValue(T value) {
    *((T*) this->value) = value;
}

#include "Var_templateToString.h"
#include "Var_getValue.h"
#include "Var_constructors.h"
#include "Var_operators.h"

template<>
std::string Var<std::string>::asString() const { 
    return Var<std::string>::getValue(*this); 
}

template<>
std::string Var<char>::asString() const { 
    return std::string((char *) this->value, 1); 
}

#endif